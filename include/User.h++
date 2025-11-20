#pragma once
#include <string>
#include <vector>

struct Book {
    int id;
    std::string title;
    std::string author;
    int year;
    bool isBorrowed = false;
};

struct History {
    int bookId;
    
    std::string title;
};

class User {
private:
    std::vector<Book>* books;             // pointer to all books in library
    std::vector<History> borrowHistory;   // user's own history

public:
    User(std::vector<Book>* libraryBooks);

    void userMenu();
    void listAllBooks();
    void findBook();
    void findByAuthor();
    void findByTitle();
    void findByYear();

    void borrowBook();
    void viewBorrowHistory();
    void deleteBook();    // delete from library list

    void exitMenu();
};
