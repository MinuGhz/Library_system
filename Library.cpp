#include "Library.h"
#include "iostream"

using namespace std;

Library::Library() {
    cout<<"Library!!!!!!!\n";
    Books = new Book[10000];
    vipbooks = new VIPbook[100];
    members = new Member[1000];
    vipmembers = new VIPmember[1000];
    staffs = new Staff[30];

}

Library::~Library(){
    cout<<"~ is running!\n";
    delete []Books;
    delete []vipbooks;
    delete []members;
    delete []vipmembers;
    delete []staffs;
}

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
        if(members[i].get_person_name() == "0") {
            members[i].set_member(name,ID , id);
            return;
        }
    }

    cout<<"Sorry! we can't accept new member.\n";
}

void Library::addVIPMember(const Person &member) {
    cout<<"Enter The new VIP Member ID: ";
    string id;
    cin>>id;

        int i , j;
        for(i=0 ; i<1000 ; i++){
            if(members[i].get_memberID() == id) {
                makeVIP(members[i]);
                  return;
            }
        }


    string name = member.get_person_name();
    string ID = member.get_person_ID();

    for(j=0 ; j<1000 ; j++){

        if(members[j].get_person_name() == "0"){
        members[j].set_member(name,ID,id);
        makeVIP(members[j]);

       return;
        }

    }

}


void Library::makeVIP(const Member &newvip) {
    if(search_vipmember(newvip)) return;

    int j;
    for(j=0 ; j<1000 ; j++){
        if(members[j].get_person_ID() == newvip.get_person_ID()) break;
    }


        string name = members[j].get_person_name();
        string ID = members[j].get_person_ID();
        string memID = members[j].get_memberID();
        for(int i=0 ; i<1000 ; i++){
            if(vipmembers[i].get_person_name() == "0"){
                vipmembers[i].set_member(name,ID,memID);
                vipmembers[i].set_vip_sub(2);
                return;
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
        if(staffs[i].get_person_name() == "0") {
            staffs[i].set_staff(name,ID , id);
            return;
        }
    }

    cout<<"Sorry! we can't hire new staff.\n";

}

void Library::addBook(const Book &newbook) {


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
        if(Books[i].get_book_ID() == "0") {
            if(condition == "available") Books[i].set_book(name,ID,false);
            else Books[i].set_book(name,ID,true);
            cout<<newbook.get_book_name()<<" has been successfully added!\n";
            return;
        }
    }

    cout<<"Sorry! we can't add new book.\n";
}


void Library::addVIPbook(const Book &newvip) {

   if (search_bookID(newvip.get_book_ID())){
       cout<<"The book that you are trying to add is a general book!\n";
       cout<<"If you want to add it to the VIP list, please remove the book from the general list first!\n";
       return;
   }

   if(search_vipbook(newvip)){
       cout<<newvip.get_book_name()<<" is currently on the VIP list\n";
       return;
   }

    string name = newvip.get_book_name();
    string ID = newvip.get_book_ID();
    string condition = newvip.get_book_condition();

   for(int i=0 ; i<100 ; i++){
       if(vipbooks[i].get_book_name() == "0"){
           if(condition == "available") vipbooks[i].set_book(name,ID,false);
           else vipbooks[i].set_book(name,ID,true);
           cout<<newvip.get_book_name()<<" has been successfully added!\n";
           return;
       }
   }

   cout<<"Sorry! We can't add new VIP book\n";

}

/***********************************************************************************************************************/

void Library::removeBook(Book &book) {
     for(int i=0 ; i<10000 ; i++){
         if(Books[i].get_book_ID() == book.get_book_ID()){
             Books[i].set_book("0","0",false);
             cout<<book.get_book_name()<<" has been successfully deleted!\n";
             return;
         }
     }
     cout<<book.get_book_name()<<" was not found!\n";
}

void Library::removeVIPBook(Book &book) {
    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == book.get_book_ID()){
            vipbooks[i].set_book("0" , "0" , false);
            cout<<book.get_book_name()<<" has been successfully deleted from VIP list!\n";
            return;
        }
    }
    cout<<book.get_book_name()<<" was not found!\n";
}

void Library::removeStaff(Person &ex) {
    for(int i=0 ; i<30 ; i++){
        if(staffs[i].get_person_ID() == ex.get_person_ID()){
            staffs[i].set_staff("0","0","0");
            cout<<ex.get_person_name()<<" has been successfully removed from staff list!\n";
            return;
        }
    }
    cout<<"The staff was not found!\n";
}

void Library::removeMember(Person &ex) {
    for(int i=0 ; i<1000 ; i++){
        if(members[i].get_person_ID() == ex.get_person_ID() ){
            if(search_vipmember(members[i])){
                removeVIPMember(ex);
            }
            members[i].set_member("0","0","0");
            cout<<ex.get_person_name()<<" has been successfully removed from member list!\n";

                return;
            }
        }

      cout<<"The member was not found!\n";
    }




void Library::removeVIPMember(const Person &ex) {
    for(int i=0 ; i<1000 ; i++){
        if(vipmembers[i].get_person_ID() == ex.get_person_ID()){
            vipmembers[i].set_vip("0","0","0");
            cout<<ex.get_person_name()<<" has been successfully removed from VIP list!\n";
        }
    }
    cout<<"The VIP member was not found!\n";
}
/**********************************************************************************************************************/

void Library::borrowBook(string memberid, string bookid) {
    if(!search_memberID(memberid)) {
        cout<<"You can't borrow books because you do not have an account!\n";
        return;
    }

    if(!search_bookID(bookid) && !search_vipbookID(bookid)){
        cout<<"Sorry! We don't have this book in the library.\n";
        return;
    }

    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == bookid){
            if(vipbooks[i].get_book_condition() == "borrowed"){
                cout<<"Sorry!"<<vipbooks[i].get_book_name()<<" is currently unavailable!\n";
                return;
            }
            else{
                for(int j=0 ; j<1000 ; j++){
                    if(vipmembers[j].get_memberID() == memberid){

                        string name = vipbooks[i].get_book_name();
                        string ID = vipbooks[i].get_book_ID();
                        Book temporaryobj(name,ID , true);

                        if(vipmembers[j].set_book(temporaryobj)) {
                            int sub = vipmembers[j].get_vip_sub() - 1;
                            if (sub == 0) removeVIPMember(memberid);
                            else vipmembers[j].set_vip_sub(sub);
                            return;
                        }
                    }


                }
                    cout<<"'"<<memberid<<"' Sorry! You do not have access to this book because you are not a VIP member!\n";
                    return;
            }
        }
    }

    for(int i=0 ; i<10000 ; i++){
        if(Books[i].get_book_ID() == bookid){
            if(Books[i].get_book_condition() == "borrowed"){
                cout<<"Sorry! The book is currently unavailable!\n";
                return;
            }
            else{
                for(int j=0 ; j<1000 ; j++){
                    if(members[j].get_memberID() == memberid){
                        members[j].set_book(Books[i]);
                    }
                }
            }
        }
    }

}
/**********************************************************************************************************************/

void Library::returnBook(string memberid, string bookid) {

    int number;

    for(int i=0 ; i<1000 ; i++){
        if(members[i].get_memberID() == memberid){
            number = i;
            break;
        }
    }


    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == bookid){
            string name = vipbooks[i].get_book_name();
            string ID = vipbooks[i].get_book_ID();

            Book temporary(name , ID , true);
            members[number].return_book(temporary);

            vipbooks[i].change_condition();

            return;
        }
    }

    for(int i=0 ; i<10000 ; i++) {
        if (Books[i].get_book_ID() == bookid) {
            members[number].return_book(Books[i]);
            return;

        }
    }

       cout<<"Something went wrong\n";

}
/**********************************************************************************************************************/


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

bool Library::search_vipbookID(string ID) {
    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == ID) return true;
    }

    return false;
}


bool Library::search_vipmember(const Member &someone) {
    for(int i=0 ; i<1000 ; i++){
        if(vipmembers[i].get_person_ID() == someone.get_person_ID()) return true;
    }

    return false;
}

bool Library::search_vipbook(const Book &isVIP) {
    for(int i=0 ; i<100 ; i++)
        if(vipbooks[i].get_book_ID() == isVIP.get_book_ID())
            return true;

    return false;
}

