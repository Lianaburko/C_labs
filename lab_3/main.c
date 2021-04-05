#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int* reverse_string(int* str, int n) {
    int i1 = 0, i2 = n - 1;
    while (i1 < i2) {
        int temp = str[i1];
        str[i1] = str[i2];
        str[i2] = temp;
        i1++;
        i2--;
    }
    return str;
}

int find_max_i(int** array, int n, int m){
    int max = 0, i_max;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (max < array[i][j]) {
                max = array[i][j];
                i_max = i;
            }
        }
    }
    return i_max;
}

int find_max_j(int** array, int n, int m){
    int max = 0, j_max;
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (max < array[i][j]) {
                max = array[i][j];
                j_max = j;
            }
        }
    }
    return j_max;
}

int main() {
    srand(time(NULL));
    int n, m;
    printf("Enter the size of your array");
    scanf("%d%d", &n, &m);
    int i = 0, j = 0, k = 0;
    int** array = (int**)malloc(n * sizeof(int*));
    if (array == NULL) {
        printf("MEMORY ERROR");
        return 0;
    }
    for (i = 0; i < n; i++) {
        array[i] = (int*)malloc(m * sizeof(int));
        if (array[i] == NULL) {
            for (k = 0; k < i; k++) {
                free((array[k]));
            }
            free(array);
            printf("MEMORY ERROR");
            return 0;
        }
    }

    int max = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            array[i][j] = (rand() % 1000);  
            printf("%d ", array[i][j]);
        }
    printf("\n");
    }

    int i_max = find_max_i(array, n, m);
    int j_max = find_max_j(array, n, m);

    for (i = i_max; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            array[i][j] = array[i + 1][j];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = j_max; j < m - 1; j++) {
            array[i][j] = array[i][j + 1];
        }
    }
    printf("\n\n");
    for (i = 0; i < n - 1; i++) {
        array[i] = (int*)realloc(array[i], (m - 1) * sizeof(int));
        if (array[i] == NULL) {
            for (k = 0; k < i; k++) {
                free((array[k]));
            }
            free(array);
            printf("MEMORY ERROR");
            return 0;
        }
    }
    array = (int**)realloc(array, (n - 1) * sizeof(int*));
    if (array == NULL) {
        printf("MEMORY ERROR");
        return 0;
    }

    for (i = 0; i < n - 1; i++) {
        array[i] = reverse_string(array[i], m - 1);
    }

    for (int j = 0; j < m - 1; j++) {
        int i1 = n - 2;
        for (int i = 0; i < i1; i++, i1--) {
            int temp = array[i][j];
            array[i][j] = array[i1][j];
            array[i1][j] = temp;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            printf("%4d", array[i][j]);
            }
        printf("\n");
    }

free(array);
return 0;
}