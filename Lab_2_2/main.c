#include <stdio.h>
#include <math.h>
#include "main.h"

int Checking_input(double angle) {
    if (angle < -1.57 || angle > 1.57) {
        printf("Choose another angle\n");
        return 0;
    }
    else {
        return 1;
    }
}

int Checking_infelicity(double infelicity) {
    if (infelicity > 0) {
        return 1;
    }
    else {
        printf("Choose another infelicity\n");
        return 0;
    }
}

int Calculating(double angle, double infelicity) {
    double sum = 0;
    int counter = 0, fact = 1;
    while (fabs(sin(angle) - sum) >= infelicity) {
        if (counter % 2 == 1) {
            sum -= pow(angle, 2 * counter + 1) / fact;
        }
        else {
            sum += pow(angle, 2 * counter + 1) / fact;
        }
        counter++;
        fact *= (2 * counter) * (2 * counter + 1);
    }
    return counter;
}

int main() {
    double angle, infelicity;
    printf("enter your angle (use '.' and it must be |angle| < 1.57)\n");
    while (scanf("%lf", &angle) != 1 || Checking_input(angle) == 0) {
        printf("incorrect input\n");
        while (getchar() != '\n') {
        }
    }
    printf("enter your infelicity(dont use negative numbers)\n");
    while (scanf("%lf", &infelicity) != 1 || Checking_infelicity(infelicity) == 0) {
        printf("incorrect input\n");
        while (getchar() != '\n') {
        }
    }
    printf("Amount of steps is %d", Calculating(angle, infelicity));
    return 0;
}
