#ifndef MAIN_H
#define MAIN_H

#include <queue>

struct Main_Conscript {
    int time;
    int arr_of_time[5];
};

struct Conscript {
    int time;
};

struct Room {
    int current_time;
    std::queue<int> queue1;
};

void adding_cons(Room rooms[5]);
int adding_special_cons(Main_Conscript &cons1, Room rooms[5]);

#endif

