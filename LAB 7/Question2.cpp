#include <string>
using namespace std;
#include <iostream>

class Product {
protected:
    string productID, productName;
    double price;
    int stockQuantity;

public:
    Product(string id, string n, double p, int c = 0) : productID(id), productName(n), price(p), stockQuantity(c) {}

    virtual void applyDiscount(double p) {
        if (p > 100) p = 100;
        price -= price * (p / 100.0);
    }

    virtual double calculateTotalPrice(int q) {
        return price * q;
    }

    virtual void displayProduct() const {
        cout << "==========PRODUCT INFORMATION===========\n";
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Stock Quantity: " << stockQuantity << endl;
    }

    friend ostream &operator<<(ostream &out, const Product &p) {
        p.displayProduct();
        return out;
    }

    Product operator+(const Product &other) {
        return Product("Bulk", "Bulk Purchase", price + other.price, stockQuantity + other.stockQuantity);
    }

    virtual ~Product() {}
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(string id, string n, double p, int c, int w, string b) : Product(id, n, p, c), warrantyPeriod(w), brand(b) {}

    void displayProduct() const override {
        Product::displayProduct();
        cout << "Warranty Period: " << warrantyPeriod << " years" << endl;
        cout << "Brand: " << brand << endl;
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;

public:
    Clothing(string id, string n, double p, int c, string s, string cl, string f) : Product(id, n, p, c), size(s), color(cl), fabricMaterial(f) {}

    void applyDiscount(double p) override {
        if (p > 25) p = 25;
        Product::applyDiscount(p);
    }

    void displayProduct() const override {
        Product::displayProduct();
        cout << "Size: " << size << endl;
        cout << "Color: " << color << endl;
        cout << "Fabric Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(string id, string n, double p, int c, string e, int ca)
        : Product(id, n, p, c), expirationDate(e), calories(ca) {}

    double calculateTotalPrice(int q) const override {
        double t = Product::calculateTotalPrice(q);
        if (q > 5)
            t *= 0.9;
        return t;
    }

    void displayProduct() const override {
        Product::displayProduct();
        cout << "Expiration Date: " << expirationDate << endl;
        cout << "Calories: " << calories << endl;
    }
};

class Book : public Product {
    string author, genre;

public:
    Book(string id, string n, double p, int c, string a, string g) : Product(id, n, p, c), author(a), genre(g) {}

    void displayProduct() const override {
        Product::displayProduct();
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
    }
};

int main() {
    Electronics e("E123", "Refrigerator", 100000, 10, 2, "Orient");
    Clothing c("C456", "T-Shirt", 1500, 20, "M", "Black", "Cotton");
    FoodItem f("F789", "Chocolate Cake", 2000, 15, "2025-06-30", 450);
    Book b("B101", "The Great Gatsby", 1200, 5, "F. Scott Fitzgerald", "Fiction");

    cout << "\nDisplaying Products:\n";
    e.displayProduct();
    cout << "\n";
    c.displayProduct();
    cout << "\n";
    f.displayProduct();
    cout << "\n";
    b.displayProduct();
    cout << "\n";

    cout << "Applying Discounts...\n";
    e.applyDiscount(10);
    c.applyDiscount(30);
    f.applyDiscount(5);
    b.applyDiscount(15);

    cout << "\nUpdated Prices after Discount:\n";
    cout << e << "\n" << c << "\n" << f << "\n" << b << "\n";

    int qty = 7;
    cout << "\nTotal Price for " << qty << " Chocolate Cakes: " << f.calculateTotalPrice(qty) << " (10% discount applied on bulk order)\n";

    Product bulkPurchase = e + c;
    cout << "\nBulk Purchase Product Details:\n";
    cout << bulkPurchase << "\n";

    return 0;
}
