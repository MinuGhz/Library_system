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
            return;
        }
    }

    cout<<"Sorry! we can't accept new member.\n";
}

void Library::addVIPMember(const Person &member) {
    cout<<"Enter The new Member ID: ";
    string id;
    cin>>id;

        int i , j;
        for(i=0 ; i<1000 ; i++){
            if(members[i].get_person_name() == "") j=i;
            if(members[i].get_memberID() == id) {
                makeVIP(members[i]);
                  return;
            }
        }

    string name = member.get_person_name();
    string ID = member.get_person_ID();

    members[j].set_member(name,ID,id);
    makeVIP(members[j]);

    return;

}


void Library::makeVIP(const Member &newvip) {

    if(search_vipmember(newvip)) return;
    else{
        string name = newvip.get_person_name();
        string ID = newvip.get_person_ID();
        string MemberId = newvip.get_memberID();

    for(int i=0 ; i<100 ; i++)
        if(vipmembers[i].get_memberID() == ""){
            vipmembers[i].set_vip(name,ID,MemberId);
        }
    }
}

void Library::addStaff(const Person &newstaff) {

    cout<<"Enter The new Staff ID: ";
    string id;
    cin>>id;

    while(search_staffID(id)){
        cout<<"The ID is now in use! please try another ID: ";
        cin>>id;
    }

    string name = newstaff.get_person_name();
    string ID = newstaff.get_person_ID();

    int i;
    for(i=0 ; i<30 ; i++){
        if(staffs[i].get_person_name() == "") {
            staffs[i].set_staff(name,ID , id);
            return;
        }
    }

    cout<<"Sorry! we can't hire new staff.\n";

}

void Library::addBook(const Book &newbook) {

    cout<<"Enter The new Book ID: ";
    string id;
    cin>>id;

    while(search_bookID(id)){
        cout<<"The ID is now in use! please try another ID: ";
        cin>>id;
    }

    if(search_vipbook(newbook)){
        cout<<"The book that you are trying to add is a VIP book!\n";
        cout<<"If you want to add it to the main list, please remove the book from the VIP list first!\n";
        return;
    }

    string name = newbook.get_book_name();
    string ID = newbook.get_book_ID();
    string condition = newbook.get_book_condition();

    int i;
    for(i=0 ; i<10000 ; i++){
        if(Books[i].get_book_ID() == "") {
            if(condition == "available") Books[i].set_book(name,ID,false);
            else Books[i].set_book(name,ID,true);
            return;
        }
    }

    cout<<"Sorry! we can't add new book.\n";
}


void Library::addVIPbook(const Book &newvip) {

}



/******************************************************************************************************************/


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


bool Library::search_vipmember(const Member &someone) {
    for(int i=0 ; i<100 ; i++){
        if(vipmembers[i].get_memberID() == someone.get_memberID()) return true;
    }

    return false;
}

bool Library::search_vipbook(const Book &isVIP) {
    for(int i=0 ; i<100 ; i++)
        if(vipbooks[i].get_book_ID() == isVIP.get_book_ID())
            return true;

    return false;
}