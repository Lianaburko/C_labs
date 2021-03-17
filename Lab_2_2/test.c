#include "main.h"
#include <assert.h>

void test(){
    assert(Checking_input(-2) == 0);
    assert(Checking_input(2) == 0);
    assert(Checking_input(0.5) == 1);

    assert(Checking_infelicity(0.1) == 1);
    assert(Checking_infelicity(-0.1) == 0);

    assert(Calculating(0.5,0.1) == 1);
    assert(Calculating(1.5,0.5) == 2);
    assert(Calculating(1.5,0.004) == 3);
    assert(Calculating(1.2,0.000512) == 4);
}

#undef main 
int main(){
    test();
    return 0;
}

int Calculating(double angle, double infelicity);