
#ifndef LIBRARY_SYSTEM_VIPMEMBER_H
#define LIBRARY_SYSTEM_VIPMEMBER_H

#include "Member.h"


class VIPmember : public Member{

private:
    int RemainingBooks;

public:
    VIPmember();
    VIPmember(string,string,string);
    VIPmember(const VIPmember&);

    void set_vip(string,string,string);
    void set_vip_sub(int);

    void get_vip() const;
    int get_vip_sub() const;

    friend ostream& operator << (ostream& , const VIPmember&);
    friend istream& operator >> (istream& , VIPmember&);
};


#endif //LIBRARY_SYSTEM_VIPMEMBER_H
