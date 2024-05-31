#ifndef LIBRARY_SYSTEM_MEMBER_H
#define LIBRARY_SYSTEM_MEMBER_H

#include "Person.h"
#include "Book.h"

class Member : public Person{

private:
    string MemberID;       /*we considered that everyone has a general ID(ID in Person class)
                           and has a specific ID(staff/member/etc..)*/
    Book book[10];         /*We considered that each member can only borrow
                           10 books at a time*/

public:
    Member();                                     //default constructor
    Member(string,string,string);
    Member(const Member&);                        //copy constructor

    void set_member(string,string,string);
    void set_book(Book&);
    void get_member() const;
    string get_memberID() const;

    void return_book(Book&);


    friend ostream& operator << (ostream& , const Member&);
    friend istream& operator >> (istream& , Member&);

};


#endif //LIBRARY_SYSTEM_MEMBER_H
