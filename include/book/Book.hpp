#pragma once 

#include <iostream>
#include <string>
#include <string>
#include <vector>

using namespace std;

struct Book {
    int id ;
    string title;
    string author;
    int year;
    string country;
};

extern vector<Book> books; 