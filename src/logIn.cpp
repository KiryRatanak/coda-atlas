#include <iostream>
#include <string>

#include "LogIn.hpp"

using namespace std;

string username, password;
int roleChoice;

string adminUsername = "admin";
string adminPassword = "admin123";

string librarianUsername = "librarian";
string librarianPassword = "lib123";

string userUsername = "user";
string userPassword = "user123";

void adminFunction()
{
    cout << "Admin-specific functions will go here!" << endl;
}

void librarianFunction()
{
    cout << "Librarian-specific functions will go here!" << endl;
}

void userFunction()
{
    cout << "User-specific functions will go here!" << endl;
}

void logIn()
{

    system("cls");

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword)
    {
        roleChoice = 1;
    }
    else if (username == librarianUsername && password == librarianPassword)
    {
        roleChoice = 2;
    }
    else if (username == userUsername && password == userPassword)
    {
        roleChoice = 3;
    }
    else
    {
        cout << "Invalid username or password!" << endl;
        return;
    }

    switch (roleChoice)
    {
    case 1:
        cout << "Login successful! Welcome, Admin!" << endl;
        adminFunction();
        break;

    case 2:
        cout << "Login successful! Welcome, Librarian!" << endl;
        librarianFunction();
        break;

    case 3:
        cout << "Login successful! Welcome, User!" << endl;
        userFunction();
        break;

    default:
        cout << "Error: Invalid role!" << endl;
        break;
    }
}
