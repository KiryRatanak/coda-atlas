#pragma once
#include <string>
#include <vector>

class Account {
private:
    std::string username;
    std::string password;

public:
    Account() = default;
    Account(const std::string &username, const std::string &password);

    std::string getUsername() const;
    std::string getPassword() const;

    void setUsername(const std::string &username);
    void setPassword(const std::string &password);
};

void writeAccountsExcel(const std::string &filename, std::vector<Account> &accounts);
std::vector<Account> readAccountsExcelToVector(const std::string &filename);
void readAccountsExcel(const std::string &filename);
void signUp();
