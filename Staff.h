#ifndef LIBRARY_SYSTEM_STAFF_H
#define LIBRARY_SYSTEM_STAFF_H


#include "Person.h"


class Staff : public Person{

private:
    string StaffID;       /*we considered that everyone has a general ID(ID in Person class)
                           and has a specific ID(staff/member/etc..)*/

public:
    Staff();                                     //default constructor
    Staff(string,string,string);
    Staff(const Staff&);                         //copy constructor

    void set_staff(string,string,string);
    void get_staff() const;
    string get_staffID() const;


    friend ostream& operator << (ostream& , const Staff&);
    friend istream& operator >> (istream& , Staff&);

};


#endif //LIBRARY_SYSTEM_STAFF_H
