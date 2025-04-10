#include <iostream>
using namespace std;

class Account;

class Manager {
public:
    void deposit(Account& a, double amount);
    void withdraw(Account& a, double amount);
    void displayAccount(const Account& a);
};

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    friend class Manager;
    friend void transferFunds(Account& a, Account& c, double amount);
};

void Manager::deposit(Account& a, double amount) {
    if (amount > 0) a.balance += amount;
}

void Manager::withdraw(Account& a, double amount) {
    if (amount > 0 && amount <= a.balance) a.balance -= amount;
}

void Manager::displayAccount(const Account& a) {
    cout << "Account Number: " << a.accountNumber
         << "\nBalance: $" << a.balance << "\n";
}

void transferFunds(Account& a, Account& c, double amount) {
    if (amount > 0 && a.balance >= amount) {
        a.balance -= amount;
        c.balance += amount;
        cout << "Transfer of $" << amount << " successful.\n";
    } else {
        cout << "Transfer failed: Insufficient funds.\n";
    }
}

int main() {
    Account a("A1001", 5000);
    Account c("A1002", 3000);

    Manager manager;

    cout << "--- Initial Account Details ---\n";
    manager.displayAccount(a);
    manager.displayAccount(c);

    cout << "\n--- Performing Deposit and Withdrawal ---\n";
    manager.deposit(a, 1000);
    manager.withdraw(c, 500);

    manager.displayAccount(a);
    manager.displayAccount(c);

    cout << "\n--- TRANSFORMING FUND BETWEEN A and B ---\n";
    transferFunds(a, c, 2000);

    cout << "\n--- FINAL  ACCOUNT DETAILS ---\n";
    manager.displayAccount(a);
    manager.displayAccount(c);

    return 0;
}

