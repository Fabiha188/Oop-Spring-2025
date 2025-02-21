#include <iostream>
#include <string>
using namespace std;

class car {
public:
    string carID;  
    string brand;
    string model;
    double price;
    bool availability;
    double revenue;

    car() : carID("Unknown"), brand("Unknown"), model("Generic"), price(0.0), availability(true), revenue(0.0) {}

    car(string id, string b, string m, double p, bool a) 
        : carID(id), brand(b), model(m), price(p), availability(a), revenue(0.0) {}

    car(const car &c1) 
        : carID(c1.carID), brand(c1.brand), model(c1.model), price(c1.price), availability(c1.availability), revenue(c1.revenue) {}

    void update(string id, string b, string m, double p, bool a) {
        carID = id;
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void rentalreq(int days) {
        double cost = price * days; 

        if (availability) {
            if (days > 10) cost *= 0.90;
            else if (days > 5) cost *= 0.95;

            revenue += cost;
            availability = false;
            cout << "Car " << carID << " is rented for " << days << " days. Total price: " << cost << endl;
        } else {
            cout << "Car " << carID << " is not available\n";
        }
    }

    void display() {
        cout << "DETAILS: \n";
        cout << "Car ID: " << carID << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        cout << "Availability: " << (availability ? "Available" : "Unavailable") << endl;
        cout << "Revenue: " << revenue << endl << endl;
    }

    ~car() {
        cout << "Destructor is called for Car ID: " << carID << "\n";
    }
};

int main() {
    car c1("ABC123", "Honda", "Civic", 100000, true);
    car c2(c1);

    c1.display();
    c2.display();

    c1.update("XYZ789", "Toyota", "Corolla", 120000, true);
    c1.display();
    c2.display();

    c1.rentalreq(6);
    c1.display();

    return 0;
}
