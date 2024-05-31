#include "Person.h"
#include "iostream"
using namespace std;


Person::Person() {
    name = "" ; ID = "";
}

Person::Person(string name, string ID) {
    this->name = name;
    this->ID = ID;
}

Person::Person(const Person &someone) {
    name = someone.name;
    ID = someone.ID;
}

void Person::set_person(string name, string ID) {
    this->name = name;
    this->ID = ID;
}

void Person::get_person() const{
    cout<<"name: "<<name<<", ID: "<<ID<<endl;
}

string Person::get_person_name() const{
    return name;
}

string Person::get_person_ID() const{
    return ID;
}


ostream& operator << (ostream& output , const Person& someone){
    output<<"name: "<<someone.get_person_name()<<", ID: ";
    output<<someone.get_person_ID()<<endl;

    return output;
}


istream& operator >> (istream& input , Person& someone){
    string name , ID;
    cout<<"Enter the name: ";
    input>>name;
    cout<<"Enter the ID: ";
    input>>ID;

    someone.set_person(name,ID);

    return input;
}