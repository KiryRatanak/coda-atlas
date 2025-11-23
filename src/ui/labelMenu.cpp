#include "ui/LabelMenu.hpp"

void displayHeader()
{
    system("cls");

cout << b_blue << R"(
                                        ██╗███████╗████████╗ █████╗ ██████╗ 
                                        ██║██╔════╝╚══██╔══╝██╔══██╗██╔══██╗
                                        ██║███████╗   ██║   ███████║██║  ██║
                                        ██║╚════██║   ██║   ██╔══██║██║  ██║
                                        ██║███████║   ██║   ██║  ██║██████╔╝
                                        ╚═╝╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═════╝
)" 
<< b_green    << R"(
                  ████████╗███████╗ ██████╗██╗  ██╗      ██████╗ ██████╗  █████╗ ██████╗ ██╗   ██╗
                  ╚══██╔══╝██╔════╝██╔════╝██║  ██║      ██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝
                     ██║   █████╗  ██║     ███████║█████╗██████╔╝██████╔╝███████║██████╔╝ ╚████╔╝ 
                     ██║   ██╔══╝  ██║     ██╔══██║╚════╝██╔══██╗██╔══██╗██╔══██║██╔══██╗  ╚██╔╝  
                     ██║   ███████╗╚██████╗██║  ██║      ██████╔╝██║  ██║██║  ██║██║  ██║   ██║   
                     ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝      ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝
)"
<< b_yellow << R"(                                              ❀⊱┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄┄⊰❀)" 
<< b_purple << R"(
                           ╔═══════════════════════════════════════════════════════════╗
                           ║ )" 
<< b_cyan << R"(*****************)" 
<< b_red << R"( WELCOME TO OUR SYSTEM )" 
<< b_cyan << R"(*****************)" 
<< b_purple << R"( ║
                           ║ ╔═════╦═════════════════════════════════════════════════╗ ║
                           ║ ║  )" 
<< b_green << R"(1)" 
<< b_purple << R"(  ║ )" 
<< b_green << R"( Log In          )" 
<< b_purple << R"(                               ║ ║
                           ║ ║  )" 
<< b_blue << R"(2)" 
<< b_purple << R"(  ║ )" 
<< b_blue  << R"( Request Account )" 
<< b_purple << R"(                               ║ ║
                           ║ ║  )" 
<< b_yellow << R"(3)" 
<< b_purple << R"(  ║ )" 
<< b_yellow<< R"( About Us        )" 
<< b_purple << R"(                               ║ ║
                           ║ ║  )" 
<< b_red << R"(0)" 
<< b_purple << R"(  ║ )" 
<< b_red   << R"( Exit            )" 
<< b_purple << R"(                               ║ ║
                           ║ ╚═════╩═════════════════════════════════════════════════╝ ║
                           ╠═════════════════╦═════════════════════════════════════════╝
                           \\  )" 
<< b_green << R"(choose option )" 
<< b_purple << R"(\\
                            \\════════════════\\>>>>> )"
<< reset;

}

void displayLibrarianMenu()
{
    cout << "\n===== Library Menu =====\n";
    cout << "  1. Import Book\n";
    cout << "  2. List Books\n";
    cout << "  3. Insert Book\n";
    cout << "  4. Search Book\n";
    cout << "  5. Update Book\n";
    cout << "  6. Delete Book\n";
    cout << "  7. Amount\n";
    cout << "  0. Exit\n";
}

void displayUserMenu()
{
    cout << "\n=====[ USER MENU ]=====\n";
    cout << "1. List all books\n";
    cout << "2. Find a book\n";
    cout << "3. Borrow a book\n";
    cout << "4. View borrow history\n";
    cout << "5. Delete a book\n";
    cout << "0. Exit\n";
    cout << "Choose: ";
}

void displayAdminMenu()
{
    cout << "\n===== ADMIN MENU =====\n";
    cout << "1. Check Library\n";
    cout << "2. Manage Librarian\n";
    cout << "3. Amount\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}