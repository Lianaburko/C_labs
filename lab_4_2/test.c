  
#include "main.h"
#include <assert.h>

void test(){
    assert(match_template("rat", "_a_") == 1);
    assert(match_template("rat", "___") == 1);
    assert(match_template("cute", "__te") == 1);
    assert(match_template("date", "__te") == 1);
    assert(match_template("cute", "__t") == 0);
}

#undef main 
int main(){
    test();
    return 0;
}