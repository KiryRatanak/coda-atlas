#include "core/librarian.hpp"
#include "ui/LabelMenu.hpp"
#include "security/HidePwd.hpp"
#include "security/LibrarianPwd.hpp"
#include "validation/Validation.hpp"
#include "utils/Logger.hpp"
#include "core/Librarian.hpp"
#include "book/Book.hpp"

using namespace std;

Librarian::Librarian() {};

void Librarian::importBook(string title, string author, int year, string country)
{
    Book newBook = {title, author, year, country};
    books.push_back(newBook);
    cout << "Book imported successfully!\n";
}

void Librarian::listBooks()
{
    system("cls");
    cout << "\n===== Book List =====\n";
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }

    for (auto &b : books)
    {
        cout << b.title
             << " | " << b.author
             << " | " << b.year
             << " | " << b.country << endl;
    }
}

void Librarian::searchBooks(string title, string author, int year, string country)
{
    cout << "\n===== Search Result =====\n";
    bool found = false;

    for (auto &b : books)
    {
        if (b.title == title || b.author == author || b.year == year)
        {
            cout << b.title
                 << " | " << b.author
                 << " | " << b.year
                 << " | " << b.country << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching book found.\n";
    }
}

void Librarian::updateBook(string title)
{
    for (auto &b : books)
    {
        if (b.title == title)
        {
            cout << "Enter new title: ";
            cin >> b.title;
            cout << "Enter new author: ";
            cin >> b.author;
            cout << "Enter new year: ";
            cin >> b.year;
            cout << "Enter new country: ";
            cin >> b.country;
            cout << "Book updated successfully!\n";
            return;
        }
    }
    cout << "Book with title " << title << " not found.\n";
}

void Librarian::deleteBook(string title)
{
    auto it = remove_if(books.begin(), books.end(), [&](const Book &b)
                        { return b.title == title; });

    if (it != books.end())
    {
        books.erase(it, books.end());
        cout << "Book deleted successfully!\n";
    }
    else
    {
        cout << "Book with title " << title << " not found.\n";
    }
}

int Librarian::amount()
{
    return static_cast<int>(books.size());
}

int Librarian::librarianMenu()
{
    int option;
    string username, password;
    int attempts = 3;

    while (attempts > 0)
    {
        displayLibrarianLogIn();

        cout << "\033[7A";
        cout << "\033[22C";
        cin >> username;

        cout << "\033[3B";
        cout << "\033[22C";
        password = getPassword();

        if (checkLibrarian(username, password))
        {
            Librarian lib;
            do
            {
                displayLibrarianMenu();

                option = validatedManageLibrarian();

                if (option == 7)
                {
                    msgReturnBackInLogIn();
                    return -1;
                }

                switch (option)
                {
                case 1:
                {
                    listBooks();
                    break;
                }

                case 2:
                {
                    system("cls");
                    string title, author, country;
                    int year;
                    cout << "Enter book title: ";
                    cin >> title;
                    cout << "Enter book author: ";
                    cin >> author;
                    cout << "Enter publication year: ";
                    cin >> year;
                    cout << "Enter country: ";
                    cin >> country;
                    lib.importBook(title, author, year, country);
                    break;
                }

                case 3:
                {
                    system("cls");
                    string title, author, country;
                    int year;
                    cout << "Enter book title: ";
                    cin >> title;
                    cout << "Enter book author: ";
                    cin >> author;
                    cout << "Enter publication year: ";
                    cin >> year;
                    cout << "Enter country: ";
                    cin >> country;
                    lib.searchBooks(title, author, year, country);
                    break;
                }
                case 4:
                {
                    system("cls");
                    string title;
                    listBooks();
                    cout << "Enter book title to update: ";
                    cin >> title;
                    lib.updateBook(title);
                    break;
                }

                case 5:
                {
                    system("cls");
                    string title;
                    listBooks();
                    cout << "Enter book title to delete: ";
                    cin >> title;
                    lib.deleteBook(title);
                    break;
                }

                case 0:
                {
                    break;
                }

                default:
                {
                    cout << "Invalid option. Please try again.\n";
                    break;
                }
                }
            } while (option != 0);
        }
        else
        {
            attempts--;
            cout << endl
                 << endl
                 << endl
                 << b_red
                 << "Invalid credentials. Attempts left: " << attempts << reset << endl;
            if (attempts == 0)
            {
                cout << endl
                     << b_red << "Too many failed attempts. You are not Librarian 🫵." << reset << endl;
                msgPressEnterInLogIn();
                continue;
            }
            msgPressEnterInLogIn();
        }
    }
    return -1;
}
