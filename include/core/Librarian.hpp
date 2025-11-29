#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class Librarian
{

public:
    Librarian();

    void importBook(string title, string author, int year, string country);
    void listBooks();
    void searchBooks(string title, string author, int year, string country);
    void updateBook(string title);
    void deleteBook(string title);
    int amount();

    int librarianMenu();
};
