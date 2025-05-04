#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream file("vehicles.txt");
    if (!file.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        istringstream iss(line);
        string type, id, name, yearStr, extraData, certification;

        getline(iss, type, ',');
        getline(iss, id, ',');
        getline(iss, name, ',');
        getline(iss, yearStr, ',');
        getline(iss, extraData, ',');
        getline(iss, certification);

        
        type.erase(remove(type.begin(), type.end(), ' '), type.end());
        id.erase(remove(id.begin(), id.end(), ' '), id.end());
        name.erase(remove(name.begin(), name.end(), ' '), name.end());
        yearStr.erase(remove(yearStr.begin(), yearStr.end(), ' '), yearStr.end());
        extraData.erase(extraData.begin(), find_if(extraData.begin(), extraData.end(), [](unsigned char ch) { return !isspace(ch); }));

        int year = stoi(yearStr);
        cout << "Type: " << type << ", ID: " << id << ", Name: " << name << ", Year: " << year << endl;

        if (type == "AutonomousCar") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string valueStr = extraData.substr(pos + 1);
                float swVersion = stof(valueStr);
                cout << "Vehicle ID: " << id << " | Software Version: " << swVersion << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(":");
            if (pos != string::npos) {
                string valueStr = extraData.substr(pos + 1);
                int battery = stoi(valueStr);
                cout << "Vehicle ID: " << id << " | Battery Capacity: " << battery << " kWh" << endl;
            }
        }
        else if (type == "HybridTruck") {
            size_t cargoPos = extraData.find("Cargo:");
            size_t pipePos = extraData.find('|');
            size_t batteryPos = extraData.find("Battery:");

            if (cargoPos != string::npos && pipePos != string::npos && batteryPos != string::npos) {
                string cargoStr = extraData.substr(cargoPos + 6, pipePos - (cargoPos + 6));
                string batteryStr = extraData.substr(batteryPos + 8);

                cargoStr.erase(remove(cargoStr.begin(), cargoStr.end(), ' '), cargoStr.end());
                batteryStr.erase(remove(batteryStr.begin(), batteryStr.end(), ' '), batteryStr.end());

                int cargo = stoi(cargoStr);
                int battery = stoi(batteryStr);

                cout << "Vehicle ID: " << id 
                     << " | Cargo Capacity: " << cargo << " kg"
                     << " | Battery: " << battery << " kWh" << endl;
            } else {
                cerr << "Error parsing HybridTruck extra data for ID: " << id << endl;
            }
        }
        else {
            cerr << "Unknown vehicle type: " << type << " (ID: " << id << ")" << endl;
        }

        cout << "-----------------------------" << endl;
    }
    file.close();
    return 0;
}
