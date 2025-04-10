#include <iostream>
using namespace std;

class InventoryManager;

class Car {
private:
    string model;
    double price;

public:
    Car(string m = "", double p = 0.0) : model(m), price(p) {}

    friend class InventoryManager;
    friend void comparePrice(const Car& car1, const Car& car2);

    void displayCarDetails() const {
        cout << "Model: " << model << "\nPrice: $" << price << endl;
    }
};

class InventoryManager {
public:
    void updatePrice(Car& car, double newPrice) {
        car.price = newPrice;
    }

    void displayCarDetails(const Car& car) {
        car.displayCarDetails();
    }
};

void comparePrice(const Car& car1, const Car& car2) {
    if (car1.price > car2.price) {
        cout << car1.model << " is more expensive than " << car2.model << endl;
    } else if (car1.price < car2.price) {
        cout << car2.model << " is more expensive than " << car1.model << endl;
    } else {
        cout << car1.model << " and " << car2.model << " are priced equally." << endl;
    }
}

int main() {
    Car car1("Toyota Camry", 25000);
    Car car2("Honda Accord", 23000);

    InventoryManager manager;

    cout << "--- Initial Car Details ---\n";
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    cout << "\n--- Updating Prices ---\n";
    manager.updatePrice(car1, 24000);
    manager.updatePrice(car2, 26000);

    cout << "\n--- Updated Car Details ---\n";
    manager.displayCarDetails(car1);
    manager.displayCarDetails(car2);

    cout << "\n--- Comparing Prices ---\n";
    comparePrice(car1, car2);

    return 0;
}
