#include "user.h"

void User::lookupBook(string book)
{
    int idx = searchBooks(book);
    if (idx != -1)
    {
        cout << "\nBook found!\n";
        cout << "Book Info: " << endl;
        cout << "Title: " << BOOKS_DB[idx].title << endl;
        cout << "Author: " << BOOKS_DB[idx].author << endl;
        cout << "Publisher: " << BOOKS_DB[idx].publisher << endl;
        cout << "Release Year: " << BOOKS_DB[idx].year << endl;
        cout << "ISBN #: " << BOOKS_DB[idx].ISBN << endl;
        if (BOOKS_DB[idx].status == 'Y')
        {
            cout << "Status: AVAILABLE\n";
        }
        else
        {
            cout << "Status: NOT AVAILABLE\n";
        }
    }
    else
    {
        cout << "Book not found. Please check spelling of Book." << endl;
    }
}

void User::returnBook(string book)
{
    int idx = searchBooks(book);
    if (idx != -1)
    {
        if (BOOKS_DB[idx].status == 'Y')
        {
            cout << "Invalid return: Book has been returned already\n";
        }
        else
        {
            cout << "Requested Book has been successfully returned \n";
            BOOKS_DB[idx].status = 'Y';
            writeTofile(BOOKS_DB);
        }
    }
    else
    {
        cout << "Book not found.Please check spelling of Book." << endl;
    }
}

void User::checkOut(string book)
{
    int idx = searchBooks(book);
    if (idx != -1)
    {
        if (BOOKS_DB[idx].status == 'N')
        {
            cout << "Book is not avaliable. Book has been checked out" << endl;
        }
        else
        {
            cout << "You have successfully checked out the book\n";
            BOOKS_DB[idx].status = 'N';
            writeTofile(BOOKS_DB);
        }
    }
    else
    {
        cout << "Book not found.Please check spelling of Book." << endl;
    }
}

User::~User() {}