#include "Member.h"
#include "iostream"

using namespace std;

Member::Member() : Person(){}

Member::Member(string name, string ID , string MemberID) : Person(name,ID)
{this->MemberID = MemberID;}

Member::Member(const Member& someone){
    MemberID = someone.MemberID;
    name = someone.name;
    ID = someone.ID;
}

void Member::set_member(string name, string ID, string MemberID) {
    this->name = name;
    this->ID = ID;
    this->MemberID = MemberID;
}

void Member::get_member() const{
    cout<<"MemberID: "<<MemberID<<endl;
    get_person();
}

inline string Member::get_memberID() const{
    return MemberID;
}


ostream& operator << (ostream& output , const Member& someone){
    output<<"StaffID: "<<someone.get_memberID()<<endl;
    output<<"name: "<<someone.get_person_name()<<", ID: ";
    output<<someone.get_person_ID()<<endl;

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
