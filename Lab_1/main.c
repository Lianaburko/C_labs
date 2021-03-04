#include <stdio.h>
#include <math.h>

int sum_of_digits(int number) {
    int sum_of_digits = 0;
    while (number > 0) {
        int digite = number % 10;
        number = number / 10;
        sum_of_digits = digite + sum_of_digits;
    }
    return sum_of_digits;
}

int same_sum(int number){
    int a = 0;
    int sum_2 = sum_of_digits( number * 2);
    int sum_3 = sum_of_digits( number * 3);
    int sum_4 = sum_of_digits( number * 4);
    int sum_5 = sum_of_digits( number * 5);
    int sum_6 = sum_of_digits( number * 6); 
    int sum_7 = sum_of_digits( number * 7);
    int sum_8 = sum_of_digits( number * 8);
    int sum_9 = sum_of_digits( number * 9);
    if (sum_2 == sum_3 && sum_3 == sum_4 && sum_4 == sum_5 && sum_5 == sum_6 && sum_6 == sum_7 && sum_7 == sum_8 && sum_8 == sum_9) {
        return a = 1;
    } 
    else {
        return a = 0;
    }
}

int main(void) {
    printf("%s\n", "Numbers, that have the same sum, at multiplication on 2,3,4,5,6,7,8,9:");
    int i;
    for (i = 10; i < 100; i++) {
        if (same_sum(i)){
            printf("%d%s", i, " ");
        }
    }
    return 0;
}
