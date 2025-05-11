#include <iostream>
#include <stdexcept>
using namespace std;

class InventoryException : public exception {
protected:
    string message;

public:
    InventoryException(string msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NegativeStockException : public InventoryException {
public:
    NegativeStockException(string msg) : InventoryException(msg) {}
};

class OverCapacityException : public InventoryException {
public:
    OverCapacityException(string msg) : InventoryException(msg) {}
};

template <typename T>
class InventoryItem {
private:
    T stock;
    T maxCapacity;

public:
    InventoryItem(T maxCap) : stock(0), maxCapacity(maxCap) {}

    void setStock(T value) {
        if (value < 0) {
            throw NegativeStockException("Stock cannot be negative.");
        }
        if (value > maxCapacity) {
            throw OverCapacityException("Stock exceeds maximum allowed capacity.");
        }
        stock = value;
        cout << "Stock set to: " << stock << endl;
    }

    T getStock() const {
        return stock;
    }
};

int main() {
    InventoryItem<int> item(100);

    try {
        cout << "Attempting to set stock to -5..." << endl;
        item.setStock(-5);
    }
    catch (InventoryException& e) {
        cout << "Caught NegativeStockException: " << e.what() << endl;
    }

    try {
        cout << "Attempting to set stock to 120 (max 100)..." << endl;
        item.setStock(120);
    }
    catch (InventoryException& e) {
        cout << "Caught OverCapacityException: " << e.what() << endl;
    }

    return 0;
}
