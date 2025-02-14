#include <iostream>
#include <string>
using namespace std;

class Library {
string name[100];
int available[100];
string borrowedBy[100];
int count;

public:
Library() {
count = 0;
}

void add(string n) {
if (count < 100) {
name[count] = n;
available[count] = 1;
borrowedBy[count] = "";
cout << "The book '" << n << "' added successfully.\n";
count++;
} else {
cout << "Library limit is full.\n";
}
}

void borrow(string bn, string n) {
int c = 0;
for (int i = 0; i < count; i++) {
if (name[i] == bn && available[i] == 1) {
available[i] = 0;
borrowedBy[i] = n;
cout << "Book '" << bn << "' borrowed by " << n << ".\n";

return;
}
if (name[i] == bn && available[i] == 0) {
cout << "The book '" << bn << "' is already borrowed by " << borrowedBy[i] << ".\n";
return;
}
}
cout << "The book '" << bn << "' does not exist in the library.\n";
}

void display() {
cout << "\n........................ LIBRARY SYSTEM ....................................\n";
for (int i = 0; i < count; i++) {
cout << "Book Name: " << name[i] << endl;
if (available[i] == 0) {
cout << "Status: Borrowed\n";
cout << "Borrowed by: " << borrowedBy[i] << endl;
} else {
cout << "Status: Available\n";
}
cout << "--------------------------------------\n";
}
cout << "........................ END ....................................\n";
}
};

int main() {
Library l1;
l1.add("Alone");
l1.add("Harry Potter");
l1.add("The Alchemist");
l1.add("The Twilight Saga");
l1.display();

l1.borrow("The Twilight Saga", "Zain");

l1.borrow("Faith", "Jitesh");
l1.display();

return 0;
}
