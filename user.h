#pragma once

#include <iostream>
#include "library.h"
using namespace std;
class User : public Library
{
private:
public:
    User() {}

    void checkOut(string);
    void returnBook(string);
    void lookupBook(string);
    ~User();
};
