#include "library.h"
using namespace std;

void Library::readFile()
{
    ifstream DB_FILE("DATABASE.txt");
    try
    {
        if (!DB_FILE)
        {
            throw - 1;
        }
    }
    catch (int e)
    {
        cout << "There was an error opening the DATABASE FILE!!!" << endl;
        exit(0);
    }
    string arr[6];
    string line;

    while (getline(DB_FILE, line))
    {
        int i = 0;
        stringstream ss(line);
        string token;
        books b;
        while (getline(ss, token, ','))
        {
            arr[i] = token;
            i++;
        }
        string s = arr[5];
        b.title = arr[0];
        b.author = arr[1];
        b.ISBN = arr[2];
        b.year = arr[3];
        b.publisher = arr[4];
        b.status = s[0];
        BOOKS_DB.push_back(b);
    }

    DB_FILE.close();
}

void Library::add(string title, string author, string ISBN, string year, string publisher)
{
    books newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.ISBN = ISBN;
    newBook.year = year;
    newBook.publisher = publisher;
    newBook.status = 'Y';
    BOOKS_DB.push_back(newBook);
    cout << "Added new book\n";
    writeTofile(BOOKS_DB);
}

void Library::remove(string book)
{
    int idx = searchBooks(book);
    if (idx != -1)
    {
        BOOKS_DB.erase(BOOKS_DB.begin() + idx);
        cout << "Removed book\n";
        writeTofile(BOOKS_DB);
    }
    else
    {
        cout << "Book not found" << endl;
    }
}

int Library::searchBooks(string book)
{
    for (int i = 0; i < BOOKS_DB.size(); i++)
    {
        if (BOOKS_DB[i].title == book)
        {
            return i;
        }
    }
    return -1;
}

void Library::writeTofile(vector<books> &book)
{
    ofstream DB_OUTFILE("DATABASE.txt");
    for (int i = 0; i < BOOKS_DB.size(); i++)
    {
        DB_OUTFILE << BOOKS_DB[i].title << "," << BOOKS_DB[i].author << "," << BOOKS_DB[i].ISBN << "," << BOOKS_DB[i].year << "," << BOOKS_DB[i].publisher << "," << BOOKS_DB[i].status << endl;
    }
}

void Library::displayBooks()
{
    for (int i = 0; i < BOOKS_DB.size(); i++)
    {
        cout << BOOKS_DB[i].title << ", " << BOOKS_DB[i].author << ", " << BOOKS_DB[i].ISBN << ", " << BOOKS_DB[i].year << ", " << BOOKS_DB[i].publisher << ", " << BOOKS_DB[i].status << endl;
    }
}

Library::Library()
{
    readFile();
}
Library::~Library() {}