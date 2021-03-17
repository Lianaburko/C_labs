#include "main.h"
#include <assert.h>

void test(){
    assert(Checking_input(-12,12,2020) == 0);
    assert(Checking_input(12,-12,2020) == 0);
    assert(Checking_input(12,12,-2020) == 0);
    assert(Checking_input(30,02,2020) == 0);
    assert(Checking_input(31,04,2020) == 0);
    assert(Checking_input(30,13,2020) == 0);
    assert(Checking_input(12,12,2020) == 1);
    assert(Checking_input(01,01,2020) == 1);

    assert(Amount_of_days_after_Criest(19,11,2002) == 731553);

    assert(Ordinal_number_in_the_year(03,10,2002) == 276);
    assert(Ordinal_number_in_the_year(13,06,2020) == 165);
    assert(Ordinal_number_in_the_year(25,11,1993) == 329);
}

#undef main 
int main(){
    test();
    return 0;
}