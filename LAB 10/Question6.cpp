#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class InventoryItem {
private:
    int itemID;
    char itemName[20];

public:
    InventoryItem() {
        itemID = 0;
        strcpy(itemName, "");
    }

    InventoryItem(int id, const char* name) {
        itemID = id;
        strncpy(itemName, name, sizeof(itemName) - 1);
        itemName[sizeof(itemName) - 1] = '\0'; // ensure null termination
    }

    void writeData(const char* fileName) {
        ofstream file(fileName, ios::binary | ios::app);
        if (!file) {
            cerr << "Cannot open the file for writing.\n";
            return;
        }
        file.write((char*)this, sizeof(InventoryItem));
        file.close();
        cout << "Data written successfully.\n";
    }

    void readData(const char* fileName) {
        ifstream file(fileName, ios::binary);
        if (!file) {
            cerr << "Cannot open the file for reading.\n";
            return;
        }

        InventoryItem temp;
        while (file.read((char*)&temp, sizeof(InventoryItem))) {
            cout << "ID: " << temp.itemID << "\n";
            cout << "Name: " << temp.itemName << "\n";
        }

        file.close();
        cout << "Data read successfully.\n";
    }
};


int main() {
    InventoryItem item1(101, "Wrench");
    const char* fileName = "inventory.dat";

 
    item1.writeData(fileName);


    InventoryItem reader;
    reader.readData(fileName);

    return 0;
}
