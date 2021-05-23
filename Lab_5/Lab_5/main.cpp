#include <iostream>
#include <queue>
#include <ctime>
#include "main.h"

using namespace std;

void adding_cons(Room rooms[5]) {
    int index = rand() % 5;
    int time = rand() % 10;
    rooms[index].queue1.push(time);
    rooms[index].current_time += time;
}

int adding_special_cons(Main_Conscript &cons1, Room rooms[5]) {
    int max = -1;
    for (int i = 0; i < 5; i++) {
        if (max < rooms[i].current_time){
            max = rooms[i].current_time;
        }
    }

    int number = max;
    for (int i = 0; i < 5; i++) {
        number += cons1.arr_of_time[i];
    }

    return number;
}

int main() {
    return 0;
}
