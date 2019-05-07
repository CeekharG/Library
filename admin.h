#pragma once
#include <iostream>
#include "library.h"
using namespace std;

class Admin : public Library
{
public:
    Admin();
    void addBooks(string, string, string, string, string);
    void removeBook(string);
    ~Admin();
};