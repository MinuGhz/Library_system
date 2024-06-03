#include <iostream>
#include "Book.h"
#include "VIPbook.h"
#include "Member.h"
#include "VIPmember.h"
#include "Staff.h"

#include "Library.h"

using namespace std;

int main() {
    //what are you looking for here? LOL
Person ali("ali" , "1");
Person mohammad("mohammad" , "2");
Person amir("amir" , "3");
Person javad("javad" , "4");
Person ehsan("ehsan" , "5");
Person omid("omid" , "6");
Person hamed("hamed" , "7");

Book macbeth("macbeth" , "1st" , false);
Book hamlet("hamlet" , "2nd" , false);
Book kingLear("king lear" , "3rd" , false);
VIPbook coriolanus("coriolanus" , "4th" , false);
VIPbook pricles("pricles" , "5th" , false);

Library ourLibrary;

ourLibrary.addMember(ali);
ourLibrary.addMember(mohammad);
ourLibrary.addMember(amir);

ourLibrary.addVIPMember(javad);
ourLibrary.addVIPMember(ehsan);

ourLibrary.addStaff(omid);
ourLibrary.addStaff(hamed);

ourLibrary.makeVIP(ali);


ourLibrary.addBook(macbeth);
ourLibrary.addBook(hamlet);
ourLibrary.addBook(kingLear);

ourLibrary.addVIPbook(coriolanus);
ourLibrary.addVIPbook(pricles);

/*ourLibrary.show();
ourLibrary.borrowBook("3" , "5th");
ourLibrary.show();*/

ourLibrary.borrowBook("2" , "1st");
ourLibrary.borrowBook("1" , "2nd");
ourLibrary.borrowBook("3" , "4th");
ourLibrary.borrowBook("4" , "5th");

ourLibrary.returnBook("2" , "1st");
ourLibrary.returnBook("1" , "2nd");
ourLibrary.returnBook("4" , "5th");



}
