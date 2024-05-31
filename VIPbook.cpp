#include "VIPbook.h"
#include "iostream"

using namespace std;


VIPbook::VIPbook() : Book(){}


VIPbook::VIPbook(string name, string ID, bool condition)
: Book(name,ID,condition){}


VIPbook::VIPbook(const VIPbook &vip) {
    name = vip.name;
    bookID = vip.bookID;
    isBorrowed = vip.isBorrowed;
}


