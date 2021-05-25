#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "hospital.h"

using namespace std;

int main() {
    cout << "Write the number to choose the operation:\n1-add department\n2-add doctor\n3-add patient\n4-show patient history\n0-end the program\n";
    Hospital hospital1;
    int choice;
    cin >> choice;

    Date d1 = { 10,10,2020 };
    cout << d1.day;

    return 0;
}