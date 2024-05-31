#include "VIPmember.h"
#include "iostream"

using namespace std;


VIPmember::VIPmember() : Member(){
    RemainingBooks = 2;
}

VIPmember::VIPmember(string name , string ID , string memberID , int remaining=2):
        Member(name,ID,memberID){
    RemainingBooks = remaining;
}

VIPmember::VIPmember(const VIPmember &vip) {
    name = vip.name;
    ID = vip.ID;
    MemberID = vip.MemberID;
    for(int i=0 ; i<10 ; i++) book[i] = vip.book[i];

    RemainingBooks = vip.RemainingBooks;
}


void VIPmember::set_vip(string name, string ID, string MemberID, int subs) {
    set_member(name,ID,MemberID);
    RemainingBooks = subs;
}


inline void VIPmember::set_vip_sub(int subs) {
    RemainingBooks = subs;
}

void VIPmember::get_vip() const {
    get_member();
    cout<<"Remaining vip subscription: "<<get_vip_sub()<<endl;
}


inline int VIPmember::get_vip_sub() const {
    return RemainingBooks;
}

