#include <vector>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <algorithm>
#include "hospital.h"
#include <fstream>

using namespace std;

int main() {
    cout << "Write the number to choose the operation:\n1-add department\n2-add doctor\n3-add patient\n4-add room\n5-show patient history\n0-end the program\n";
    Hospital hospital1;
    int choice;
    cin >> choice;

    if(choice == 1){
        Department dep1;
        cout << "Enter the name of department";
        string name;
        getline(cin, name);
        dep1.set_name(name);
        cout << "Enter the place of department";
        string place;
        getline(cin, place);
        dep1.set_place(place);
        hospital1.add_department(&dep1);
    }

    if (choice == 2){
        Doctor doc1;
        cout << "Enter the docs name";
        string name;
        getline(cin, name);
        doc1.set_name(name);

        cout << "Enter the speciality of the doctor";
        string speciality;
        getline(cin, speciality);
        doc1.set_speciality(speciality);

        cout << "Enter the workpost";
        string workpost;
        getline(cin, workpost);
        doc1.set_workpost(workpost);
    }

    if (choice == 3){
        Patient pat1;
        
        cout << "Enter the docs name";
        string name;
        getline(cin, name);
        pat1.set_name(name);
        
        cout << "Enter the patient's address";
        string address;
        getline(cin, address);
        pat1.set_address(address);
        
        cout << "Enter the patient's date of birth";
        Date d1;
        cout << "The day is ";
        cin >> d1.day;
        cout << "The month is";
        cin >> d1.month;
        cout << "The year is";
        cin >> d1.year;
        pat1.set_date_of_birth(d1);

        cout << "Enter the patient's date of coming";
        cout << "The day is ";
        cin >> d1.day;
        cout << "The month is";
        cin >> d1.month;
        cout << "The year is";
        cin >> d1.year;
        pat1.set_date_of_coming(d1);

        cout << "Enter the patient's date of ending therapy";
        cout << "The day is ";
        cin >> d1.day;
        cout << "The month is";
        cin >> d1.month;
        cout << "The year is";
        cin >> d1.year;
        pat1.set_date_of_ending(d1);

        cout << "Enter the patient's diagnosis";
        string diagnosis;
        getline(cin, diagnosis);
        pat1.set_diagnosis(diagnosis);
    }

    if (choice == 4){
        Room room1;
        int number; 
        cout << "The number of room is ";
        cin >> number;
        room1.set_number_of_room(number);
    }

    if (choice == 5){
        Patient pat1;
        fstream inOut;
        inOut.open("file.txt", ios::out); 
        inOut << "The name is: " << pat1.get_name();
        inOut << "\nThe diagnos is: " << pat1.get_diagnosis();
        inOut << "\nThe doctor is: " << pat1.get_doctor();
        inOut << "\nThe room is: " << pat1.get_room();

        inOut << "\nThe date of birth is: " << pat1.get_date_of_birth().day << "." << pat1.get_date_of_birth().month << "." << pat1.get_date_of_birth().year;
        inOut << "\nThe date of coming is: " << pat1.get_date_of_coming().day << "." << pat1.get_date_of_coming().month << "." << pat1.get_date_of_coming().year;
        inOut << "\nThe date of ending treatment is: " << pat1.get_date_of_ending().day << "." << pat1.get_date_of_ending().month << "." << pat1.get_date_of_ending().year;
    }

    return 0;
} 