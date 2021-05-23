#include "main.h"
#include <iostream>
#include <assert.h>
#include <queue>
#include <ctime>

using namespace std;

void test(){
    srand(time(0));
    Room rooms[5]; // array of rooms

    Main_Conscript c1;
    
    c1.arr_of_time[0] = 5;
    c1.arr_of_time[1] = 4;
    c1.arr_of_time[2] = 3;
    c1.arr_of_time[3] = 6;
    c1.arr_of_time[4] = 7;

    rooms[0].queue1.push(2);
    rooms[0].queue1.push(1);
    rooms[0].queue1.push(3);
    rooms[0].current_time = 6;

    rooms[1].queue1.push(8);
    rooms[1].queue1.push(9);
    rooms[1].queue1.push(1);
    rooms[1].queue1.push(2);
    rooms[1].current_time = 20;

    rooms[2].queue1.push(5);
    rooms[2].queue1.push(6);
    rooms[2].queue1.push(8);
    rooms[2].current_time = 19;

    rooms[3].queue1.push(3);
    rooms[3].current_time = 3;

    rooms[4].queue1.push(7);
    rooms[4].queue1.push(1);
    rooms[4].current_time = 8;

    assert(adding_special_cons(c1, rooms) == 45);
}

#undef main 
int main(){
    test();
    return 0;
}