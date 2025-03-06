#include <iostream>
#include <string>
using namespace std;

class Product {
    string productName;
    int id;
    float price;

public:
    Product() {} 

    Product(string n, int i, float p) {
        productName = n;
        id = i;
        price = p;
    }

    string getName() const { return productName; }
    int getID() const { return id; }
    float getPrice() const { return price; }

    void display() const {
        cout << "Name: " << productName << "\nID: " << id << "\nPrice: " << price << endl;
    }
};

class Inventory {
    Product* products; 
    int size; 

public:
    Inventory(int n) {
        size = n;
        products = new Product[size]; 
    }

    void inputProducts() {
        for (int i = 0; i < size; i++) {
            string name;
            int id;
            float price;

            cout << "Enter details for product " << i + 1 << ":\n";
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "ID: ";
            cin >> id;
            cout << "Price: ";
            cin >> price;

            products[i] = Product(name, id, price); 
        }
    }

    void displayProducts() const {
        cout << "\n=== Product List ===\n";
        for (int i = 0; i < size; i++) {
            products[i].display();
            cout << "--------------------\n";
        }
    }

    void searchProduct(int searchID) const {
        for (int i = 0; i < size; i++) {
            if (products[i].getID() == searchID) {
                cout << "\nProduct Found:\n";
                products[i].display();
                return;
            }
        }
        cout << "\nProduct with ID " << searchID << " not found.\n";
    }

    void sortProducts() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = i + 1; j < size; j++) {
                if (products[i].getName() > products[j].getName()) {
                    swap(products[i], products[j]);
                }
            }
        }
        cout << "\nProducts sorted alphabetically by name.\n";
    }

    ~Inventory() {
        delete[] products; 
    }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    Inventory inventory(n);
    inventory.inputProducts();
    inventory.displayProducts();
    inventory.sortProducts();
    inventory.displayProducts();

    int searchID;
    cout << "\nEnter product ID to search: ";
    cin >> searchID;
    inventory.searchProduct(searchID);

    return 0;
}
