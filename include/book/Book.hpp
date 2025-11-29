#pragma once 

#include <iostream>
#include <string>
#include <string>
#include <vector>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string country;
};

extern vector<Book> books; 