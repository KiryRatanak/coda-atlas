#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct LibrarianManagement {
    string username;
    string gender;
    string phone;
    string password;
    string address;
};

class Admin {
public:
    Admin();  // Constructor
    int adminMenu();   // Function to display admin menu
    int manageLibrarian();  // Function to manage librarian
    int amount();

private:
    // Storage for librarians
    vector<LibrarianManagement> librarians;

    // CRUD operations
    void createLibrarian();
    void updateLibrarian();
    void deleteLibrarian();
    void showLibrarians();
};