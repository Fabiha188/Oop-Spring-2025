#include <iostream>
#include <string>
using namespace std;

class car {
public:
    string brand;
    string model;
    double price;
    bool availability;

    car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
    }

    void update(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void check() {
        if (availability == true) {
            cout << "The car is available\n";
        } else {
            cout << "The car is not available\n";
        }
    }

    void rentalreq() {
        if (availability == true) {
            cout << "\nYou can rent the car at price " << price << endl;
            availability = false;
        } else {
            cout << "The car is not available\n";
        }
    }
};

int main() {
    car c1;
    c1.update("Honda", "Civic", 100000, true);
    c1.check();
    c1.rentalreq();

    return 0;
}
