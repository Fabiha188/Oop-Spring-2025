#include <iostream>
#include <string>
using namespace std;

class product {
    string productName;
    int id;
    float price;
    int count;

public:
    product() {}
    product(string n, int i, float p) {
        productName = n;
        id = i;
        price = p;
        count++;
    }
    void sort(product p1[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (p1[i].productName > p1[j].productName) {
                    product temp = p1[i];
                    p1[i] = p1[j];
                    p1[j] = temp;
                }
            }
        }
        cout << "==========================\n";
        cout << "The Sorted Details of products are:\n";
        for (int i = 0; i < n; i++) {
            cout << "Name: " << p1[i].productName << endl;
            cout << "ID: " << p1[i].id << endl;
            cout << "Price: " << p1[i].price << endl;
        }
    }
    void search(product p1[], int n, int id) {
        int check = 0, f = -1;
        for (int i = 0; i < n; i++) {
            if (p1[i].id == id) {
                f = i;
                check = 1;
                break;
            }
        }
        if (check == 1) {
            cout << "==========================\n";
            cout << "The details of product with ID: " << id << endl;
            cout << "Name: " << p1[f].productName << endl;
            cout << "ID: " << p1[f].id << endl;
            cout << "Price: " << p1[f].price << endl;
        } else {
            cout << "==========================\n";
            cout << "The details of product with ID: " << id << " is not found \n";
        }
    }
    void display(product p1[], int n) {
        cout << "==========================\n";
        cout << "The product Details are:\n";
        for (int i = 0; i < n; i++) {
            cout << "Name: " << p1[i].productName << endl;
            cout << "ID: " << p1[i].id << endl;
            cout << "Price: " << p1[i].price << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;
    cin.ignore();
    
    product products[n];
    
    for (int i = 0; i < n; i++) {
        string name;
        int id;
        float price;
        cout << "Enter details for product " << i + 1 << ":\n";
        cout << "Name: ";
        getline(cin, name);
        cout << "ID: ";
        cin >> id;
        cout << "Price: ";
        cin >> price;
        cin.ignore();
        products[i] = product(name, id, price);
    }
    
    products[0].sort(products, n);
    
    int searchID;
    cout << "Enter product ID to search: ";
    cin >> searchID;
    products[0].search(products, n, searchID);
    
    products[0].display(products, n);
    
    return 0;
}
