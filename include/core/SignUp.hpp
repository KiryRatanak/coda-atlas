#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <xlnt/xlnt.hpp>
#include <filesystem>

using namespace std;

class Account
{
private:
    string username;
    string password;

public:
    Account() = default;
    Account(const string &username, const string &password);

    string getUsername() const;
    string getPassword() const;

    void setUsername(const string &username);
    void setPassword(const string &password);

    void signUp();
    
};
