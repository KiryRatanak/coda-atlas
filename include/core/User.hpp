#pragma once
#include <vector>
#include <string>
#include "book/Book.hpp"       // best if you set include paths correctly

using namespace std;

class User {

private:
    vector<Book>* books;
    vector<string> borrowHistory;

public:
    User();  // <-- NEW default constructor
    User(vector<Book>* libraryBooks);

    void listAllBooks();
    void findBook();
    void findByAuthor();
    void findByTitle();
    void findByYear();
    void borrowBook();
    void addToBorrowHistory(const string& title); // <-- FIXED
    void userMenu();
    void viewBorrowHistory();
    void deleteBook();
};
