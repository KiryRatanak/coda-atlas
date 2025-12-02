#include "SignUp.hpp"
#include <iostream>
#include <xlnt/xlnt.hpp>

Account::Account(const std::string &username, const std::string &password)
    : username(username), password(password) {}

std::string Account::getUsername() const {
    return username;
}

std::string Account::getPassword() const {
    return password;
}

void Account::setUsername(const std::string &username) {
    this->username = username;
}

void Account::setPassword(const std::string &password) {
    this->password = password;
}

void writeAccountsExcel(const std::string &filename, std::vector<Account> &accounts) {
    xlnt::workbook wb;
    auto ws = wb.active_sheet();
    ws.title("Accounts");

    ws.cell("A1").value("Username");
    ws.cell("B1").value("Password");

    int row = 2;
    for (auto &acc : accounts) {
        ws.cell("A" + std::to_string(row)).value(acc.getUsername());
        ws.cell("B" + std::to_string(row)).value(acc.getPassword());
        row++;
    }

    wb.save(filename);
    std::cout << "Successfully saved account records!" << std::endl;
}

std::vector<Account> readAccountsExcelToVector(const std::string &filename) {
    std::vector<Account> accounts;
    xlnt::workbook wb;

    try {
        wb.load(filename);
    } catch (...) {
        std::cout << "⚠️ Could not open file. Returning empty list." << std::endl;
        return accounts;
    }

    auto ws = wb.active_sheet();
    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "Username") continue;

        std::string username = row[0].to_string();
        std::string password = row[1].to_string();
        accounts.emplace_back(username, password);
    }
    return accounts;
}

void readAccountsExcel(const std::string &filename) {
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();

    for (auto row : ws.rows(false)) {
        for (auto cell : row) {
            std::cout << cell.to_string() << " ";
        }
        std::cout << std::endl;
    }
}

void signUp() {
    std::string username;
    std::string password;
    std::vector<Account> accounts;

    // Load existing accounts (if file doesn't exist, returns empty)
    accounts = readAccountsExcelToVector("accounts.xlsx");

    std::cout << "===== Sign Up =====\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    Account newAcc(username, password);
    accounts.push_back(newAcc);

    writeAccountsExcel("accounts.xlsx", accounts);

    std::cout << "Account created successfully!\n";

    std::cout << "\n===== Current Accounts =====\n";
    readAccountsExcel("accounts.xlsx");

    return;
}
