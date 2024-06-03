
#ifndef LIBRARY_SYSTEM_LIBRARY_H
#define LIBRARY_SYSTEM_LIBRARY_H

#include "Book.h"
#include "VIPbook.h"
#include "Staff.h"
#include "Member.h"
#include "VIPmember.h"

using namespace std;

class Library {

private:
    string name;
    Staff *staffs;  /*we considered that the library doesn't need more than 30 staffs at a time*/
    Member *members;  /*we desgined a 1000 members system for this library*/
    VIPmember *vipmembers;
    Book *Books;
    VIPbook *vipbooks;


public:
    Library();
    ~Library();



    void addMember(const Person&);
    void addVIPMember(const Person&);
    void makeVIP(const Member&);
    void addStaff(const Person&);
    void addBook(const Book&);
    void addVIPbook(const Book&);

    void removeMember(Person&);
    void removeVIPMember(const Person&);
    void removeStaff(Person&);
    void removeBook(Book&);
    void removeVIPBook(Book&);

    void borrowBook(string , string);
    void returnBook(string , string);


    bool search_memberID(string);
    bool search_staffID(string);
    bool search_bookID(string);
    bool search_vipbookID(string);
    bool search_vipmember(const Member&);
    bool search_vipbook(const Book&);


};


#endif //LIBRARY_SYSTEM_LIBRARY_H
