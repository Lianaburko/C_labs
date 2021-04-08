#include "main.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int string_cmp(char *s1, char *s2) {
  int i = 0, j = 0;
  while (s1[i] != '\0' && s2[j] != '\0') {
    if (s1[i] < s2[j]) {
      return -1;
    }
    else {
      if (s1[i] > s2[j]) {
        return 1;
      }
    }
    i++;
    j++;
  }
  return 0;
}

void test(){
  char* res = (char*)malloc((30)*sizeof(char));
  if (res == NULL) {
    printf("MEMORY ERROR");
    exit(0);
  }

  char* sum = (char*)malloc((30)*sizeof(char));
  if (sum == NULL) {
    printf("MEMORY ERROR");
    exit(0);
  }

  res = "24800412111231";
  sum = calculate_numbers("11929129218921", "1281992181921");
  assert(string_cmp(sum, res) == 0);
  res = "11111112";
  sum = calculate_numbers("9999999", "11111112");
  assert(string_cmp(sum, res) == 0);
  res = "8999999001";
  sum = calculate_numbers("9999999", "999999999");
  assert(string_cmp(sum, res) == 0);
  free(sum);
  free(res);
}

#undef main 
int main(){
    test();
    return 0;
}