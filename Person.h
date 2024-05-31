

#ifndef LIBRARY_SYSTEM_PERSON_H
#define LIBRARY_SYSTEM_PERSON_H

#include "iostream"
using namespace std;

class Person {

protected:
    string name , ID;

public:
    Person();
    Person(string,string);
    Person(const Person&);

    void set_person(string,string);
    void get_person() const;
    string get_person_name() const;
    string get_person_ID() const;

    friend ostream& operator << (ostream& , const Person&);
    friend istream& operator >> (istream& , Person&);
};



#endif //LIBRARY_SYSTEM_PERSON_H
