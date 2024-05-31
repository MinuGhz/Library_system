
#ifndef LIBRARY_SYSTEM_VIPBOOK_H
#define LIBRARY_SYSTEM_VIPBOOK_H
#include "Book.h"
#include "iostream"
using namespace std;

class VIPbook : public Book{

public:
    VIPbook();
    VIPbook(string, string, bool);
    VIPbook(const VIPbook&);

    //next lines are commented to show that there is no need to define them!:)

    /*   void set_VIPbook(string, string, bool);
       void set_VIPbook_condition(bool);
       void get_VIPbook() const;
       string get_VIPbook_name() const;
       string get_VIPbook_ID() const;
       string get_VIPbook_condition() const;
   */
};

#endif //LIBRARY_SYSTEM_VIPBOOK_H
