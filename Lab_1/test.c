#include "main.h"
#include <assert.h>

int test(){
    assert(same_sum(99) == 1);
    assert(same_sum(45) == 1);
    assert(same_sum(11) == 0);
    assert(same_sum(50) == 0);
}

#undef main 
int main(){
    test();
    return 0;
}
