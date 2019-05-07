#include <iostream>
#include <string>
#include <fstream>
#include "admin.h"
#include "user.h"
using namespace std;

int main()
{
	string data;
	string title, author, ISBN, year, publisher;
	int option;
	int attempt = 0;
	string username, password;
	string fUsername, fPassword;
	bool logintest = false;
	ifstream myFile("login.txt");

	try
	{
		if (!myFile)
		{
			throw - 1;
		}
	}
	catch (int e)
	{
		cout << "There was an error opening the LOGIN file!!!" << endl;
		exit(0);
	}

	string line;
	cout << "-----------------------------------------------------------------------" << endl;
	cout << "****************Welcome to the Library Management System***************" << endl;
	cout << "-----------------------------------------------------------------------" << endl;

	do
	{
		myFile.clear();
		myFile.seekg(0, ios::beg);

		cout << "Please enter your login credentials to continue" << endl;
		cout << "Enter your username: ";
		cin >> username;
		cout << "Enter your password: ";
		cin >> password;

		while (getline(myFile, line))
		{
			stringstream ss(line);
			ss >> fUsername >> fPassword;
			if (fUsername == username && fPassword == password)
			{
				logintest = true;
				break;
			}
		}

		if (!logintest && attempt < 3)
		{
			attempt++;
			logintest = false;
			cout << "Invalid Credentials; Try Again " << 3 - attempt << " attempt left" << endl;
		}
		if (logintest)
		{
			logintest = true;
			break;
		}

		if (attempt == 3)
		{
			cout << "Your Account has been frozen. Please try again later." << endl;
			exit(0);
		}

	} while (attempt != 3);

	if (logintest)
	{
		if (username == "admin")
		{
			Admin admin;
			cout << "Logged in with Administrative Access" << endl;
			do
			{
				cout << "\nChoose an option: \n1. Add new book.\n2. Remove a book. \n3. Display all books.\n0. Quit\n";
				cin >> option;
				cin.ignore(256, '\n');
				switch (option)
				{
				case 0:
					cout << "Thanks for using our services!!" << endl;
					exit(0);

				case 1:
					cout << "Enter the title: ";
					getline(cin, title);
					cout << "Enter author: ";
					getline(cin, author);
					cout << "Enter ISBN #: ";
					getline(cin, ISBN);
					cout << "Enter the year: ";
					cin >> year;
					cin.ignore(256, '\n');
					cout << "Enter publisher: ";
					getline(cin, publisher);
					admin.addBooks(title, author, ISBN, year, publisher);
					break;
				case 2:
					cout << "Enter the book to remove: ";
					getline(cin, title);
					admin.removeBook(title);
					break;
				case 3:
					admin.displayBooks();
					break;
				default:
					cout << "Please choose the correct option\n";
					continue;
				}
			} while (option != 0);

		}
		else
		{
			User user;
			cout << "Logged in with Customer Access" << endl;
			do
			{
				cout << "\nChoose an option:\n1. Search for book.\n2. Check out book.\n3. Return book.\n4. Display all books\n0. Quit\n";
				cin >> option;
				cin.ignore(256, '\n');
				switch (option)
				{
				case 0:
					cout << "Thanks for using our services!!" << endl;
					exit(0);
				case 1:
					cout << "Enter the title: ";
					getline(cin, title);
					user.lookupBook(title);
					break;
				case 2:
					cout << "Enter the title: ";
					getline(cin, title);
					user.checkOut(title);
					break;
				case 3:
					cout << "Enter the title of the book to return: ";
					getline(cin, title);
					user.returnBook(title);
					break;
				case 4:
					user.displayBooks();
					break;
				default:
					cout << "Please choose the correct option\n";
					continue;
				}
			} while (option != 0);
			cout << "Thanks for using our services!!" << endl;
		}
	}
	return 0;
}
