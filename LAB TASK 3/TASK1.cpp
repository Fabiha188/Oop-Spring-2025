#include <iostream>
#include <string>
using namespace std;

class Wallet {
string ownerName;
double totalBalance;
string transactionHistory[100];
int count = 0;

public:
Wallet(string n, double b) {
ownerName = n;
totalBalance = b;
}

void add(double a) {
if (a > 0) {
totalBalance += a;
cout << a << " amount added in " << ownerName << "'s account" << endl;
transactionHistory[count] = "Added " + to_string(a) + " to wallet.";
count++;
} else {
cout << "The amount should be greater than 0" << endl;
}
}

void spend(double a) {
if (a > 0 && totalBalance >= a) {
totalBalance -= a;

cout << a << " amount spent. current balance " << totalBalance << endl;
transactionHistory[count] = "Spent " + to_string(a) + " from wallet.";
count++;
} else if (a <= 0) {
cout << "The amount should be greater than 0" << endl;
} else {
cout << "Your current balance is insufficient" << endl;
}
}

void display() {
cout << "Transaction History for " << ownerName << "'s account is:" << endl;
if (count == 0) {
cout << "No transactions recorded." << endl;
} else {
for (int i = 0; i < count; i++) {
cout << transactionHistory[i] << endl;
}
}
}

void check() {
cout << "Current balance: " << totalBalance << endl;
}

void lowbalance(double b) {
if (totalBalance < b) {
cout << "Your balance is below " << b << endl;
} else {
cout << "Balance is sufficient. Current amount: " << totalBalance << endl;
}
}
};

int main() {
Wallet w1("Saad", 7000);
w1.add(500);
w1.spend(5000);
w1.display();
w1.check();
w1.lowbalance(300);

return 0;
}
