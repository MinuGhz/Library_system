#include "Staff.h"
#include "iostream"
using namespace std;


Staff::Staff() : Person(){}

Staff::Staff(string name, string ID , string StaffID) : Person(name,ID)
{this->StaffID = StaffID;}

Staff::Staff(const Staff& someone){
    StaffID = someone.StaffID;
    name = someone.name;
    ID = someone.ID;
}

void Staff::set_staff(string name, string ID, string staffID) {
    this->name = name;
    this->ID = ID;
    this->StaffID = staffID;
}

void Staff::get_staff() const{
    cout<<"StaffID: "<<StaffID<<endl;
    get_person();
}

inline string Staff::get_staffID() const{
    return StaffID;
}


ostream& operator << (ostream& output , const Staff& someone){
    output<<"StaffID: "<<someone.get_staffID()<<endl;
    output<<"name: "<<someone.get_person_name()<<", ID: ";
    output<<someone.get_person_ID()<<endl;

    return output;
}

istream& operator >> (istream& input , Staff& someone){
    string name , ID , StaffID;
    cout<<"Enter the StaffID: ";
    input>>StaffID;
    cout<<"Enter the name: ";
    input>>name;
    cout<<"Enter the ID: ";
    input>>ID;

    someone.set_staff(name,ID, StaffID);

    return input;
}