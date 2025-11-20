#include <iostream>
#include <string>

#include "LogIn.h++"

using namespace std;

// Function prototypes for role-specific actions
void adminFunction();
void librarianFunction();
void userFunction();

int main() {
    system("cls");
    
    string username, password;
    int roleChoice;

    string adminUsername = "admin";
    string adminPassword = "admin123";

    string librarianUsername = "librarian";
    string librarianPassword = "lib123";

    string userUsername = "user";
    string userPassword = "user123";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword) {
        roleChoice = 1;
    } 
    else if (username == librarianUsername && password == librarianPassword) {
        roleChoice = 2;
    }
    else if (username == userUsername && password == userPassword) {
        roleChoice = 3;
    }
    else {
        cout << "Invalid username or password!" << endl;
        return 1;
    }

    switch (roleChoice) {
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

    return 0;
}

void adminFunction() {
    cout << "Admin-specific functions will go here!" << endl;
}

void librarianFunction() {
    cout << "Librarian-specific functions will go here!" << endl;
}

void userFunction() {
    cout << "User-specific functions will go here!" << endl;
}
