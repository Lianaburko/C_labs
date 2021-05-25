#include <string>
#include <vector>
#include <iostream>
#include "hospital.h"

using namespace std;

void Hospital::set_name(string name) {
    this->name = name;
}

string Hospital::get_name() {
    return name;
}

vector <Department*> Hospital::get_name_of_department() {
    return this->departments;
}

void Hospital::add_department(Department* department) {
    this->departments.push_back(department);
}

void Department::set_name(string name) {
    this->name = name;
}

string Department::get_name() {
    return name;
}

void Department::set_place(string place) {
    this->place = place;
}

string Department::get_place() {
    return place;
}

void Department::add_room(Room* room) {
    this->rooms.push_back(room);
}

vector <Doctor*> Department::get_doctors() {
    return this->doctors;
}

vector <Room*> Department::get_rooms() {
    return this->rooms;
}

void Department::add_doctor(Doctor* doctor) {
    this->doctors.push_back(doctor);
}

void Doctor::set_name(string name) {
    this->name = name;
}

string Doctor::get_name() {
    return name;
}

void Doctor::set_speciality(string speciality) {
    this->speciality = speciality;
}

string Doctor::get_speciality() {
    return speciality;
}

void Doctor::set_workpost(string workpost) {
    this->workpost = workpost;
}

string Doctor::get_workpost() {
    return workpost;
}

void Doctor::set_department(Department* department) {
    this->department = department;
    department->add_doctor(this);
}

string Doctor::get_department() {
    return department->get_name();
}

void Doctor::add_patient(Patient* patient) {
    this->patients.push_back(patient);
}

vector <Patient*> Doctor::get_patients() {
    return this->patients;
}

void Patient::set_name(string name) {
    this->name = name;
}
string Patient::get_name() {
    return name;
}
void Patient::set_address(string address) {
    this->address = address;
}
string Patient::get_address() {
    return address;
}
void Patient::set_diagnosis(string diagnosis) {
    this->diagnosis = diagnosis;
}
string Patient::get_diagnosis() {
    return diagnosis;
}
void Patient::set_date_of_birth(Date date_of_birth) {
    this->date_of_birth = date_of_birth;
}
Date Patient::get_date_of_birth() {
    return date_of_birth;
}
void Patient::set_date_of_coming(Date date_of_coming) {
    this->date_of_coming = date_of_coming;
}
Date Patient::get_date_of_coming() {
    return date_of_coming;
}
void Patient::set_date_of_ending(Date date_of_ending) {
    this->date_of_ending = date_of_ending;
}
Date Patient::get_date_of_ending() {
    return date_of_ending;
}

void Patient::set_doctor(Doctor* doctor) {
    this->doctor = doctor;
    doctor->add_patient(this);
}

string Patient::get_doctor() {
    return doctor->get_name();
}

void Patient::set_room(Room* room) {
    this->room = room;
    room->add_patient(this);
}

int Patient::get_room() {
    return room->get_number_of_room();
}

int Days(Date date) {
    return (date.year - 2021) * 365 + date.month * 30 + date.day;
}

void Room::add_patient(Patient* patient) {
    this->current_number_of_patients = current_number_of_patients++;
    if (current_number_of_patients > 4) {
        int min = Days(patients[0]->get_date_of_ending());
        int index = 0;
        for (int i = 1; i < 4; i++) {
            if (min > Days(patients[i]->get_date_of_ending())) {
                min = Days(patients[i]->get_date_of_ending());
                index = i;
            }
        }
        cout << "There is no free places in the room. Wait for" << patients[index]->get_date_of_ending().day;
        cout << "." << patients[index]->get_date_of_ending().month << "." << patients[index]->get_date_of_ending().year;
    }
    else {
        this->patients.push_back(patient);
    }
}

vector <Patient*> Room::get_patients() {
    return this->patients;
}

void Room::set_number_of_room(int number_of_room) {
    this->number_of_room = number_of_room;
}

int Room::get_number_of_room() {
    return number_of_room;
}

void Room::set_department(Department* department) {
    this->department = department;
    department->add_room(this);
}

string Room::get_department() {
    return department->get_name();
}
