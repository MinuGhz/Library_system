#include "Library.h"
#include "iostream"

using namespace std;


void Library::addMember(const Person &member) {
    cout<<"Enter The new Member ID: ";
    string id;
    cin>>id;

    while(search_memberID(id)){
        cout<<"The ID is now in use! please try another ID: ";
        cin>>id;
    }

    string name = member.get_person_name();
    string ID = member.get_person_ID();

    int i;
    for(i=0 ; i<1000 ; i++){
        if(members[i].get_person_name() == "") {
            members[i].set_member(name,ID , id);
        }
    }

    if(i==1000) cout<<"Sorry! we can't accept new member.\n";
}



bool Library::search_memberID(string ID) {
    for(int i=0 ; i<1000 ; i++){
        if(members[i].get_memberID() == ID) return true;
    }
    return false;
}

bool Library::search_staffID(string ID) {
    for(int i=0 ; i<30 ; i++){
        if(staffs[i].get_staffID() == ID) return true;
    }
    return false;
}

bool Library::search_bookID(string ID) {
    for(int i=0 ; i<10000 ; i++){
        if(Books[i].get_book_ID() == ID) return true;
    }
    return false;
}
