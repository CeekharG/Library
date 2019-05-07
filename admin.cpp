#include "admin.h"

Admin::Admin() {}
void Admin::addBooks(string title, string author, string ISBN, string year, string publisher)
{
    add(title, author, ISBN, year, publisher);
}

void Admin::removeBook(string book)
{
    remove(book);
}

Admin::~Admin() {}