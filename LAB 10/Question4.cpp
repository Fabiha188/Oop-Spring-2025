#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    ifstream file("vehicles.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
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

        // Trim spaces
        type.erase(remove(type.begin(), type.end(), ' '), type.end());

        if (type == "AutonomousCar") {
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string versionStr = extraData.substr(pos + 1);
                float softwareVersion = stof(versionStr);
                cout << "Vehicle ID: " << id << " | Software Version: " << softwareVersion << endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t pos = extraData.find(':');
            if (pos != string::npos) {
                string batteryStr = extraData.substr(pos + 1);
                int battery = stoi(batteryStr);
                cout << "Vehicle ID: " << id << " | Battery Capacity: " << battery << " kWh" << endl;
            }
        }
    }

    file.close();
    return 0;
}
