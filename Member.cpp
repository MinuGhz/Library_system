#include "Member.h"
#include "iostream"

using namespace std;

Member::Member() : Person(){
    book = new Book[10];
    MemberID = "0";
}

Member::Member(string name, string ID , string MemberID) : Person(name,ID)
{   book = new Book[10];
    this->MemberID = MemberID;}

Member::Member(const Person& newMember) : Person(newMember){
    book = new Book[10];
    MemberID = "0";
}

Member::Member(const Member& someone){
    MemberID = someone.MemberID;
    name = someone.name;
    ID = someone.ID;
    book = new Book[10];
    for(int i=0 ; i<10 ; i++){
        book[i] = someone.book[i];
    }
}

void Member::set_member(string n, string Id, string MemID) {
    name = n;
    ID = Id;
    MemberID = MemID;
}

Member::~Member(){
    delete []book;
}

bool Member::set_book(Book &asked) {
    int i;
    for(i=0 ; i<10 ; i++) {
        if (book[i].get_book_name() == asked.get_book_name()) {
            cout << "The book is currently on loan to this member!\n";
            return false;
        }
    }
    for(int i=0 ; i<10 ; i++){
        if(book[i].get_book_name() == "0"){
            asked.change_condition();
            book[i] = asked;
            return true;
        }
    }

        cout<<"this member can't borrow any other book!";
        cout<<"(because they have currently borrowed 10 book)\n";

        return false;
}


void Member::get_member() const{
    cout<<"MemberID: "<<MemberID<<endl;
    get_person();
}

string Member::get_memberID() const{
    return MemberID;
}

void Member::return_book(Book &borrowed) {
    int i;

    for(i=0 ; i<10 ; i++){

        if(book[i].get_book_name() == borrowed.get_book_name()) {
            book[i].set_book("0" , "0" , false);
            borrowed.change_condition();
            return;
        }
    }
    cout<<"The book was not found in Member book list!\n";
}


ostream& operator << (ostream& output , const Member& someone){
    output<<"MemberID: "<<someone.get_memberID()<<endl;
    output<<"name: "<<someone.get_person_name()<<", ID: ";
    output<<someone.get_person_ID()<<endl;
    output<<"Borrowed books: \n";
    for(int i=0 ; i<10 ; i++) output<<someone.book[i];
    output<<endl;

    return output;
}


istream& operator >> (istream& input , Member& someone){
    string name , ID , MemberID;
    cout<<"Enter the StaffID: ";
    input>>MemberID;
    cout<<"Enter the name: ";
    input>>name;
    cout<<"Enter the ID: ";
    input>>ID;

    someone.set_member(name,ID, MemberID);

    return input;
}
