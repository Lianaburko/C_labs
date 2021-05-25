#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

class Hospital;
class Department;
class Doctor;
class Room;
class Patient;

class Hospital {
private:
    string name;
    vector <Department*> departments;
public:
    string get_name();
    void set_name(string name);
    void add_department(Department* department);
    vector <Department*> get_name_of_department();
};

class Department {
private:
    string name;
    string place;
    Hospital* hospital;
    vector <Room*> rooms;
    vector <Doctor*> doctors;
public:
    void set_name(string name);
    string get_name();
    void set_place(string place);
    string get_place();
    void add_room(Room* room);
    vector <Room*> get_rooms();
    void add_doctor(Doctor* doctor);
    vector <Doctor*> get_doctors();
};

class Room {
private:
    int number_of_room;
    int amount_of_places = 4;
    int current_number_of_patients;
    vector <Patient*> patients;
    Department* department;
public:
    void set_number_of_room(int number_of_room);
    int get_number_of_room();
    void add_patient(Patient* patient);
    vector <Patient*> get_patients();
    void set_department(Department* department);
    string get_department();
};

class Doctor {
private:
    Department* department;
    vector <Patient*> patients;
    string name;
    string speciality;
    string workpost;
    Patient* patient;
public:
    void set_name(string name);
    string get_name();
    void set_speciality(string speciality);
    string get_speciality();
    void set_workpost(string workpost);
    string get_workpost();
    void set_department(Department* department);
    string get_department();
    void add_patient(Patient* patient);
    vector <Patient*> get_patients();
};

class Patient {
private:
    string name;
    string address;
    string diagnosis;
    Date date_of_birth;
    Date date_of_coming;
    Date date_of_ending;
    int number_of_room;
    Doctor* doctor;
    Room* room; 
public:
    void set_name(string name);
    string get_name();
    void set_address(string address);
    string get_address();
    void set_diagnosis(string diagnosis);
    string get_diagnosis();
    void set_date_of_birth(Date date_of_birth);
    Date get_date_of_birth();
    void set_date_of_coming(Date date_of_coming);
    Date get_date_of_coming();
    void set_date_of_ending(Date date_of_ending);
    Date get_date_of_ending();
    void set_number_of_room(int number_of_room);
    int get_number_of_room();
    void set_doctor(Doctor* doctor);
    string get_doctor();
    void set_room(Room* room);
    int get_room();
};