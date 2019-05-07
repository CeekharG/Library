#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Library
{
private:
    struct books
    {
        string title, author, ISBN, year, publisher;
        char status;
    };
    void readFile();

protected:
    vector<books> BOOKS_DB;
    void add(string, string, string, string, string);
    void remove(string);
    int searchBooks(string);
    void writeTofile(vector<books> &);

public:
    Library();
    void displayBooks();
    ~Library();
};
