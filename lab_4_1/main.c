#include <stdio.h>
#include <stdlib.h>

unsigned int string_length(char* str) {
    unsigned int size = 0;
    while (str[size] != '\0') {
        size++;
    }
    return size;
}

char* calculate_numbers(char* dig1, char* dig2){
    unsigned int size1 = string_length(dig1);
    unsigned int size2 = string_length(dig2);

    int max; 
    if (size1 > size2){
        max = size1;
    }
    else {
        max = size2;
    }

    int i = 0, j = 0;
    char* result = (char*)malloc((max+1)*sizeof(char));
    if (result == NULL) {
        printf("MEMORY ERROR");
        return 0;
    }
    int plus_to_value = 0;

    while ((size2 != 0 && size1 > 0) || (size2 > 0 && size1 != 0) || (size2 != 0 && size1 != 0)) {
        int first_dig = dig1[size1 - 1] - '0';
        int second_dig = dig2[size2 - 1] - '0';
        int value = first_dig + second_dig + plus_to_value;
        if (value >= 10) {
            result[j] = (value) % 10 + '0';
            plus_to_value = value / 10;
        }
        else {
            result[j] = value  + '0';
            plus_to_value = 0;
        }
        size2--;
        size1--;
        j++;
    }

    if (size2 != 0) {
        for (i = size2; i != 0; i--) {
            int value = dig2[i - 1] - '0';
            value += plus_to_value;
            if (value >= 10) {
                result[j] = (value) % 10  + '0';
                plus_to_value = value / 10;
            }
            else {
                result[j] = value  + '0';
                plus_to_value = 0;
            }
            j++;
        }
    }

    if (size1 != 0) {
        for (i = size1; i != 0; i--) {
            int value = dig1[i - 1] - '0';
            value += plus_to_value;
            if (value >= 10) {
                result[j] = (value) % 10 + '0';
                plus_to_value = value / 10;
            }
            else {
                result[j] = value + '0';
                plus_to_value = 0;
            }
        j++;
        }
    }

    if (plus_to_value != 0) {
        result[j] = plus_to_value + '0';
        j++;
    }

    return result;
}

int main() {
    char dig1[30];
    char dig2[30]; 

    scanf("%s", dig1);
    scanf("%s", dig2);

    unsigned int size1 = string_length(dig1);
    unsigned int size2 = string_length(dig2);

    int max; 
    if (size1 > size2){
        max = size1;
    }
    else {
        max = size2;
    }

    char* result = calculate_numbers(dig1, dig2);
        
    int i;
    for (i = string_length(result)-1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    free(result);
    return 0;
}