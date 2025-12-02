#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "book/Book.hpp"
#include "core/History.hpp"

class User {

public:
    User();  // if you need default constructor

    int userMenu();

    void listBooksInlabrary();
    void findBook();
    void findByAuthor();
    void findByTitle();
    void findByYear();

    void borrowBook();
    void viewBorrowHistory();
    void deleteBook();
};
