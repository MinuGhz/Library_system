#ifndef LIBRARY_SYSTEM_MEMBER_H
#define LIBRARY_SYSTEM_MEMBER_H

#include "Person.h"
#include "Book.h"

class Member : public Person{

private:
    string MemberID;       /*we considered that everyone has a general ID(ID in Person class)
                           and has a specific ID(staff/member/etc..)*/
    Book* book;

public:
    Member();                                     //default constructor
    Member(string,string,string);
    Member(const Member&);                         //copy constructor

    void set_member(string,string,string);
    void get_member() const;
    string get_memberID() const;


    friend ostream& operator << (ostream& , const Member&);
    friend istream& operator >> (istream& , Member&);

};


#endif //LIBRARY_SYSTEM_MEMBER_H
