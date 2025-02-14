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

    car(const car &c1) { 
        brand = c1.brand;
        model = c1.model;
        price = c1.price;
        availability = c1.availability;
    }

    void update(string b, string m, double p, bool a) {
        brand = b;
        model = m;
        price = p;
        availability = a;
    }

    void display() {
        cout << "DETAILS: \n";
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Price: " << price << endl;
        
        string status;
        if (availability == true) {
            status = "Available";
        } else {
            status = "Unavailable";
        }
        
        cout << "Availability: " << status << endl << endl;
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

    c1.update("Toyota", "Corolla", 120000, false);
    c1.display();
    c2.display();

    return 0;
}
