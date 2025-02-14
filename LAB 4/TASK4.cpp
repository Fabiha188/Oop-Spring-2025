#include <iostream>
#include <string>
using namespace std;

class car {
public:
    string brand;
    string model;
    double price;
    bool availability;
    double revenue;

    car() {
        brand = "Unknown";
        model = "Generic";
        price = 0.0;
        availability = true;
        revenue = 0.0;
    }

    car(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
        revenue = 0.0;
    }

    car(const car &c1) { 
        brand = c1.brand;
        model = c1.model;
        price = c1.price;
        availability = c1.availability;
        revenue = c1.revenue;
    }

    void update(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void rentalreq(int days) {
        double cost = price * days; 

        if (availability == true) {
            if (days > 10) {
                cost *= 0.90; 
            } else if (days > 5) {
                cost *= 0.95; 
            }

            revenue += cost; 
            availability = false; 

            cout << "The car is rented for " << days << " days. Total price: " << cost << endl;
        } else {
            cout << "The car is not available\n";
        }
    }

    void display() {
        cout << "DETAILS: \n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability: " << (availability ? "Available" : "Unavailable") << endl;
        cout << "Revenue: " << revenue << endl << endl;
    }

    ~car() {
        cout << "Destructor is called!! \n";
    }
};

int main() {
    car c1("Honda", "Civic", 100000, true);
    car c2(c1);

    c1.display();
    c2.display();

    c1.update("Toyota", "Corolla", 120000, true);
    c1.display();
    c2.display();

    c1.rentalreq(6);
    c1.display();

    return 0;
}
