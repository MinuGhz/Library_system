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

    for(int i=0 ; i<1000 ; i++)
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

   if (search_bookID(newvip.get_book_ID())){
       cout<<"The book that you are trying to add is a general book!\n";
       cout<<"If you want to add it to the VIP list, please remove the book from the general list first!\n";
       return;
   }

   if(search_vipbook(newvip)){
       cout<<"The book is currently on the VIP list\n";
       return;
   }

    string name = newvip.get_book_name();
    string ID = newvip.get_book_ID();
    string condition = newvip.get_book_condition();

   for(int i=0 ; i<100 ; i++){
       if(vipbooks[i].get_book_name() == ""){
           if(condition == "available") vipbooks[i].set_book(name,ID,false);
           else vipbooks[i].set_book(name,ID,true);
           cout<<"The book has been successfully added!\n";
           return;
       }
   }

   cout<<"Sorry! We can't add new VIP book\n";

}

/***********************************************************************************************************************/

void Library::removeBook(Book &book) {
     for(int i=0 ; i<10000 ; i++){
         if(Books[i].get_book_ID() == book.get_book_ID()){
             Books[i].set_book("","",false);
             cout<<"The book has been successfully deleted!\n";
             return;
         }
     }
     cout<<"The book was not found!\n";
}

void Library::removeVIPBook(Book &book) {
    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == book.get_book_ID()){
            vipbooks[i].set_book("" , "" , false);
            cout<<"The book has been successfully deleted from VIP list!\n";
            return;
        }
    }
    cout<<"The book was not found!\n";
}

void Library::removeStaff(Person &ex) {
    for(int i=0 ; i<30 ; i++){
        if(staffs[i].get_person_ID() == ex.get_person_ID()){
            staffs[i].set_staff("","","");
            cout<<"the staff has been successfully removed!\n";
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
            members[i].set_member("","","");
            cout<<"The member has been successfully removed!\n";

                return;
            }
        }

      cout<<"The member was not found!\n";
    }




void Library::removeVIPMember(const Person &ex) {
    for(int i=0 ; i<1000 ; i++){
        if(vipmembers[i].get_person_ID() == ex.get_person_ID()){
            vipmembers[i].set_vip("","","");
            cout<<"The VIP member has been successfully removed from VIP list!\n";
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
                cout<<"Sorry! The book is currently unavailable!\n";
                return;
            }
            else{
                for(int j=0 ; j<1000 ; j++){
                    if(vipmembers[j].get_memberID() == memberid){
                        if(vipmembers[j].set_book(vipbooks[i])) {
                            int sub = vipmembers[j].get_vip_sub() - 1;
                            if (sub == 0) removeVIPMember(memberid);
                            else vipmembers[j].set_vip_sub(sub);
                            return;
                        }
                    }


                }
                    cout<<"Sorry! You do not have access to this book because you are not a VIP member!\n";
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

    for(int i=0 ; i<10000 ; i++) {
        if (Books[i].get_book_ID() == bookid) {
            members[number].return_book(Books[i]);
            return;

        }
    }

    for(int i=0 ; i<100 ; i++){
        if(vipbooks[i].get_book_ID() == bookid){
            members[number].return_book(vipbooks[i]);
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