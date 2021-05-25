#include <assert.h>
#include "hospital.h"

int main(){
    // hosp
    Hospital hosp1;
    hosp1.set_name("Hospital #1");
    assert(hosp1.get_name() == "Hospital #1");

    //dep
    Department dep1;
    Department dep2;
    dep1.set_name("Heart department");
    dep2.set_name("Eye department");
    assert(dep1.get_name() == "Heart department");
    assert(dep2.get_name() == "Eye department");

    dep1.set_place("4 floor");
    dep2.set_place("3 floor");
    assert(dep1.get_place() == "4 floor");
    assert(dep2.get_place() == "3 floor");
 
    //doctor
    Doctor doc1;
    Doctor doc2;
    Doctor doc3;

    doc1.set_name("Ivanov Ivan Ivanovich");
    doc1.set_speciality ("Heart surgeon");
    doc1.set_workpost("Head of heart department");
    assert(doc1.get_name() == "Ivanov Ivan Ivanovich");
    assert(doc1.get_speciality() == "Heart surgeon");
    assert(doc1.get_workpost() == "Head of heart department");

    doc2.set_name("Petrov Petr Petrovich");
    doc2.set_speciality("Anesthetist");
    doc2.set_workpost("Main anesthetist");
    assert(doc2.get_name() == "Petrov Petr Petrovich");
    assert(doc2.get_speciality() == "Anesthetist");
    assert(doc2.get_workpost() == "Main anesthetist");

    doc3.set_name("Vasiliy Vasilievich Vasiliev");
    doc3.set_speciality("Eye surgeon");
    doc3.set_workpost("Main eye surgeon");
    assert(doc3.get_name() == "Vasiliy Vasilievich Vasiliev");
    assert(doc3.get_speciality() == "Eye surgeon");
    assert(doc3.get_workpost() == "Main eye surgeon");
    
    // patient
    Patient pat1;
    Patient pat2;
    Patient pat3;
    Patient pat4;
    Patient pat5;

    pat1.set_name("Vasya Pupkin");
    pat1.set_diagnosis("Hypertension");
    pat1.set_date_of_birth({10,10,1988});
    pat1.set_date_of_coming({5,12,2020});
    pat1.set_date_of_ending({10,2,2021});
    pat1.set_address("Minsk, Angarskaya street, 5");
    
    assert(pat1.get_name() == "Vasya Pupkin");
    assert(pat1.get_diagnosis() == "Hypertension");
    assert(pat1.get_address() == "Minsk, Angarskaya street, 5");
    Date date1 = pat1.get_date_of_birth();
    assert(date1.day == 10);
    assert(date1.month == 10);
    assert(date1.year == 1988);
    Date date2 = pat1.get_date_of_coming();
    assert(date2.day == 5);
    assert(date2.month == 12);
    assert(date2.year == 2020);
    Date date3 = pat1.get_date_of_ending();
    assert(date3.day == 10);
    assert(date3.month == 2);
    assert(date3.year == 2021);

    //room
    Room room1;
    room1.set_number_of_room(106);
    assert(room1.get_number_of_room() == 106);


    hosp1.add_department(&dep1);
    hosp1.add_department(&dep2);

    return 0;
}