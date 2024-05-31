#include "Member.h"
#include "iostream"

using namespace std;

Member::Member() : Person(){
    MemberID = "";
}

Member::Member(string name, string ID , string MemberID) : Person(name,ID)
{this->MemberID = MemberID;}

Member::Member(const Member& someone){
    MemberID = someone.MemberID;
    name = someone.name;
    ID = someone.ID;
    for(int i=0 ; i<10 ; i++){
        book[i] = someone.book[i];
    }
}

void Member::set_member(string name, string ID, string MemberID) {
    this->name = name;
    this->ID = ID;
    this->MemberID = MemberID;
}

void Member::set_book(Book &asked) {
    int i;
    for(i=0 ; i<10 ; i++){
        if(book[i].get_book_name() == asked.get_book_name())
        {cout<<"The book is currently on loan to this member!\n";
            break;}
        if(book[i].get_book_name() == ""){
            book[i] = asked;
            break;
        }
    }
    if(i==10) {
        cout<<"this member can't borrow any other book!";
        cout<<"(because they have currently borrowed 10 book)\n";
    }
}

void Member::get_member() const{
    cout<<"MemberID: "<<MemberID<<endl;
    get_person();
}

inline string Member::get_memberID() const{
    return MemberID;
}

void Member::return_book(Book &borrowed) {
    int i;
    for(i=0 ; i<10 ; i++){
        if(book[i].get_book_ID() == borrowed.get_book_ID()) {
            book[i].set_book("" , "" , false);
        }
    }
    if(i==10) cout<<"The book was not found in Member book list!\n";
}

ostream& operator << (ostream& output , const Member& someone){
    output<<"StaffID: "<<someone.get_memberID()<<endl;
    output<<"name: "<<someone.get_person_name()<<", ID: ";
    output<<someone.get_person_ID()<<endl;
    output<<"Borrowed books: \n";
    for(int i=0 ; i<10 ; i++) output<<someone.book[i];

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
