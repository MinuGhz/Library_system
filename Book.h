

#ifndef LIBRARY_SYSTEM_BOOK_H
#define LIBRARY_SYSTEM_BOOK_H

#include "iostream"

using namespace std;

class Book {
protected:
    string name;
    string bookID;
    bool isBorrowed;

public:
    Book();
    Book(string , string , bool);
    Book(const Book&);

    void set_book(string , string , bool);
    void get_book() const;
    string get_book_name() const;
    string get_book_ID() const;
    string get_book_condition() const;


    friend ostream& operator << (ostream& , const Book&);
    friend istream& operator >> (istream& , Book&);
};



#endif //LIBRARY_SYSTEM_BOOK_H
