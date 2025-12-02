#include "core/SignUp.hpp"

const std::string ACCOUNT_FILE = "data/account/accounts.xlsx";

// ======================= Account Class =========================

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

// ======================= WRITE EXCEL =========================

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
    std::cout << "✔ Successfully saved account records to " << filename << "\n";
}

// ======================= READ EXCEL TO VECTOR =========================

std::vector<Account> readAccountsExcelToVector(const std::string &filename) {
    std::vector<Account> accounts;
    xlnt::workbook wb;

    try {
        wb.load(filename);
    } catch (...) {
        std::cout << "⚠️ File does not exist. Creating a new one.\n";
        return accounts;
    }

    auto ws = wb.active_sheet();

    for (auto row : ws.rows(false)) {
        if (row[0].to_string() == "Username") continue;

        accounts.emplace_back(row[0].to_string(), row[1].to_string());
    }

    return accounts;
}

// ======================= PRINT EXCEL =========================

void readAccountsExcel(const std::string &filename) {
    xlnt::workbook wb;
    wb.load(filename);
    auto ws = wb.active_sheet();

    for (auto row : ws.rows(false)) {
        for (auto cell : row) {
            std::cout << cell.to_string() << " ";
        }
        std::cout << "\n";
    }
}

// ======================= SIGN UP =========================

void signUp() {
    std::string username, password;

    // Make sure folder exists
    std::filesystem::create_directories("data/account");

    // Load existing accounts
    std::vector<Account> accounts = readAccountsExcelToVector(ACCOUNT_FILE);

    std::cout << "===== Sign Up =====\n";
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    accounts.emplace_back(username, password);

    // Save updated list
    writeAccountsExcel(ACCOUNT_FILE, accounts);

    std::cout << "✔ Account created successfully!\n";

    std::cout << "\n===== Current Accounts =====\n";
    readAccountsExcel(ACCOUNT_FILE);

    return;
}
