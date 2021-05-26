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
    Department deps[10];
    int counter_deps = 0;
    Patient pats[80];
    int counter_pats = 0;
    Doctor docs[20];
    int counter_docs = 0;
    Room rooms[20];
    int counter_rooms = 0;

    int choice = -1;
    while (choice != 0) {
        cin >> choice;
        if (choice == 1) {
            Department dep1;
            if (counter_deps > 9) {
                cout << "There is no place for your department";
            }
            else {
                cout << "Enter the name of department" << endl;
                string name;
                getchar();
                getline(cin, name);
                dep1.set_name(name);
                cout << "Enter the place of department" << endl;
                string place;
                getchar();
                getline(cin, place);
                dep1.set_place(place);
                hospital1.add_department(&dep1);
                deps[counter_deps] = dep1;
                cout << "Choose another sub to add" << endl;
            }
            counter_deps++;
        }

        if (choice == 2) {
            Doctor doc1;
            if (counter_docs > 19) {
                cout << "There are no workplaces for the doctors";
            }
            else {
                cout << "Enter the docs name" << endl;
                string name;
                getchar();
                getline(cin, name);
                doc1.set_name(name);

                cout << "Enter the speciality of the doctor" << endl;
                string speciality;
                getline(cin, speciality);
                doc1.set_speciality(speciality);

                cout << "Enter the workpost" << endl;
                string workpost;
                getline(cin, workpost);
                doc1.set_workpost(workpost);

                int dep_number;
                cout << "Choose department, to what you want add the doctor" << endl;
                for (int i = 0; i < counter_deps; i++) {
                    cout << "Enter the " << i << " to add to the " << deps[i].get_name() << endl;
                }
                cin >> dep_number;
                deps[dep_number].add_doctor(&doc1);
                doc1.set_department(&deps[dep_number]);

                docs[counter_docs] = doc1;
                int pat_number;
                cout << "Choose patient to add to the doctor" << endl;
                for (int i = 0; i < counter_pats; i++) {
                    cout << "Enter the " << i << " to add to the " << pats[i].get_name() << endl;
                }
                cin >> pat_number;
                pats[pat_number].set_doctor(&doc1);
                doc1.add_patient(&pats[pat_number]);
                cout << "Choose another sub to add" << endl;
            }
            counter_docs++;
        }

        if (choice == 3) {
            Patient pat1;
            if (counter_pats > 79) {
                cout << "There is no room at hospital" << endl;
            }
            else {
                pats[counter_pats] = pat1;
                cout << "Enter the patients name" << endl;
                getchar();
                string name;
                getline(cin, name);
                pat1.set_name(name);

                cout << "Enter the patient's address" << endl;
                getchar();
                string address;
                getline(cin, address);
                pat1.set_address(address);

                cout << "Enter the patient's date of birth" << endl;
                Date d1;
                cout << "The day is ";
                cin >> d1.day;
                cout << "The month is";
                cin >> d1.month;
                cout << "The year is";
                cin >> d1.year;
                pat1.set_date_of_birth(d1);

                cout << "Enter the patient's date of coming" << endl;
                cout << "The day is ";
                cin >> d1.day;
                cout << "The month is";
                cin >> d1.month;
                cout << "The year is";
                cin >> d1.year;
                pat1.set_date_of_coming(d1);

                cout << "Enter the patient's date of ending therapy" << endl;
                cout << "The day is  ";
                cin >> d1.day;
                cout << "The month is  ";
                cin >> d1.month;
                cout << "The year is  ";
                cin >> d1.year;
                pat1.set_date_of_ending(d1);

                cout << "Enter the patient's diagnosis" << endl;
                string diagnosis;
                getline(cin, diagnosis);
                pat1.set_diagnosis(diagnosis);

                int doc_number;
                cout << "Choose doctor to add to the patient add" << endl;
                for (int i = 0; i < counter_docs; i++) {
                    cout << "Enter the " << i << " to add to the " << docs[i].get_name() << endl;
                }
                cin >> doc_number;
                docs[doc_number].add_patient(&pat1);
                pat1.set_doctor(&docs[doc_number]);

                int room_number;
                cout << "Choose the room to add the patient" << endl;
                for (int i = 0; i < counter_rooms; i++) {
                    cout << "Enter the " << i << " to add to the " << rooms[i].get_number_of_room() << endl;
                }
                cin >> room_number;
                rooms[room_number].add_patient(&pat1);
                pat1.set_room(&rooms[room_number]);
                cout << "Choose another sub to add" << endl;
            }
            counter_pats++;
        }

        if (choice == 4) {
            Room room1;
            if (counter_rooms > 20) {
                cout << "There is no place to add rooms" << endl;
            }
            else {
                int number;
                cout << "The number of room is " << endl;
                cin >> number;
                room1.set_number_of_room(number);

                int pat_number;
                cout << "Choose the patient to the room" << endl;
                for (int i = 0; i < counter_pats; i++) {
                    cout << "Enter the" << i << "to add to the" << pats[i].get_name() << endl;
                }
                cin >> pat_number;
                room1.add_patient(&pats[pat_number]);
                pats[pat_number].set_room(&rooms[counter_rooms]);
                cout << "Choose another sub to add" << endl;
            }
        }

        if (choice == 5) {
            cout << "Choose the patient whose history you want to read" << endl;
            int number;
            for (int i = 0; i < counter_pats; i++) {
                cout << "Enter the" << i << "to read the history of" << pats[i].get_name() << endl;
            }
            cin >> number;

            fstream inOut;
            inOut.open("file.txt", ios::out);
            inOut << "The name is: " << pats[number].get_name();
            inOut << "\nThe diagnos is: " << pats[number].get_diagnosis();
            inOut << "\nThe doctor is: " << pats[number].get_doctor();
            inOut << "\nThe room is: " << pats[number].get_room();

            inOut << "\nThe date of birth is: " << pats[number].get_date_of_birth().day << "." << pats[number].get_date_of_birth().month << "." << pats[number].get_date_of_birth().year;
            inOut << "\nThe date of coming is: " << pats[number].get_date_of_coming().day << "." << pats[number].get_date_of_coming().month << "." << pats[number].get_date_of_coming().year;
            inOut << "\nThe date of ending treatment is: " << pats[number].get_date_of_ending().day << "." << pats[number].get_date_of_ending().month << "." << pats[number].get_date_of_ending().year;
            cout << "Choose another sub to add" << endl;
        }
    }

    return 0;
}