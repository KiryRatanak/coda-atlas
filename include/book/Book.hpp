#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "core/User.hpp"

using namespace std;

class Book {private : 
    vector<Book> libraryBooks; 
public:
    string title;
    string author;
    int year;
    string country;
    bool borrowed = false;
    
    Book(string title, string author, int year, string country)
        : title(title), author(author), year(year), country(country) {}
};


