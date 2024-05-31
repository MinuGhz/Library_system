#include "Book.h"
#include "iostream"

using namespace std;

Book::Book(){
    name = "" ; bookID = "";
    isBorrowed = false;
}

Book::Book(string name , string ID , bool condition) {
    set_book(name , ID , condition);
}

Book::Book(const Book & book) {
    name = book.name;
    bookID = book.bookID;
    isBorrowed = book.isBorrowed;
}


void Book::set_book(string name, string bookID, bool isBorrowed) {
    this->name = name;
    this->bookID = bookID;
    this->isBorrowed = isBorrowed;
}

void Book::get_book() const {
    cout<<"name: "<<name<<", bookID: "<<bookID;
    cout<<"condition: "<<get_book_condition()<<endl;
}

inline string Book::get_book_name() const {
    return name;
}

inline string Book::get_book_ID() const {
    return bookID;
}

string Book::get_book_condition() const {
    if(isBorrowed) return "borrowed";
    else return "available";
}

ostream& operator << (ostream& output , const Book& book){
    output<<"name: "<<book.get_book_name()<<", bookID: "<<book.get_book_ID();
    output<<"condition: "<<book.get_book_condition()<<endl;

    return output;
}


istream& operator >> (istream& input , Book& book){
    string name, ID, condition;
    cout<<"Enter the book name: ";
    input>>name;
    cout<<"Enter the book ID: ";
    input>>ID;
    cout<<"Is the book currently in the library?(yes/no): ";
    input>>condition;

    if(condition == "yes") book.set_book(name,ID, false);
    else book.set_book(name,ID, true);

    return input;
}