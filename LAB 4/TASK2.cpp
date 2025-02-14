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

    car(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void update(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void rentalreq(int days) {
        if (availability == true) {
            if (days > 10) {
                cout << "\nYou can rent the car at price " << price * 0.90 << " with discount 10%" << endl;
            } else if (days > 5) {
                cout << "\nYou can rent the car at price " << price * 0.95 << " with discount 5%" << endl;
            } else {
                cout << "\nYou can rent the car at price " << price << endl;
            }
            availability = false;
        } else {
            cout << "The car is not available\n";
        }
    }
};

int main() {
    car c1("Honda", "Civic", 100000, true);

    c1.rentalreq(5);
    c1.rentalreq(3);

    return 0;
}
