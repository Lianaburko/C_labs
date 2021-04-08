#include <stdio.h>
#include "main.h"
 
unsigned int string_length(char* str) {
    unsigned int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

int match_template(char* word, char* combination) {
    for(; *word == *combination || *combination == '_'; word++, combination++) {
        if(*word == '\0'){
            return 1;
        }          
    }
    return 0;
}
 
int main() {
    char word[15];
    char combination[15];
    int size;
    FILE* fp;
    
    printf("Enter the word with '_' ");
    scanf("%s", combination);
    size = string_length(combination);
    
    fp = fopen("words.txt", "r");
    if (fp = NULL) {
        printf("Can't open the file");
        return 1;
    }
    printf("all combinations with (%s) are:\n", combination);
    while(fscanf(fp, "%s", word) > 0) {
        if(string_length(word) != size){
            continue;
        }
        if(match_template(word, combination)){
            printf("%s\n", word);
        }
    }
    fclose(fp);
    return 0; 
}