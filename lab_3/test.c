#include <stdlib.h>
#include "main.h"
#include <assert.h>

void test(){
    int n = 4, m = 5;
    int i = 0, j = 0, k = 0;
    int** array = (int**)malloc(n * sizeof(int*));
    if (array == NULL) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        array[i] = (int*)malloc(m * sizeof(int));
        if (array[i] == NULL) {
            for (k = 0; k < i; k++) {
                free((array[k]));
            }
            free(array);
            return 0;
        }
    }

    int max = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[i][j] = (rand() % 1000);  
        }
    }    
  
    int i_max = find_max_i(array, n, m);
    int j_max = find_max_j(array, n, m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            assert(array[i][j] <= array[i_max][j_max]);
        }
    }    
    free(array);
}

#undef main 
int main(){
    test();
    return 0;
}