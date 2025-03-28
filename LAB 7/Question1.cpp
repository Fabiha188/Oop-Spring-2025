#include <iostream>
using namespace std;
#include <string>

class Device {
protected:
    string deviceID, deviceName, location;
    bool status;

public:
    Device(string i, string n, string l = "") : deviceID(i), deviceName(n), location(l) {
        status = false;
    }

    virtual void turnOn() {
        status = true;
        cout << deviceName << " turned on\n";
    }

    virtual void turnOff() {
        status = false;
        cout << deviceName << " turned off\n";
    }

    virtual void display() const {
        cout << "Device ID: " << deviceID << endl;
        cout << "Device Name: " << deviceName << endl;
        cout << "Status: " << (status ? "ON" : "OFF") << endl;
        if (!location.empty()) {
            cout << "Location: " << location << endl;
        }
    }

    virtual void getStatus() const {
        if (status) {
            cout << deviceName << " is turned on" << endl;
        } else {
            cout << deviceName << " is turned off" << endl;
        }
    }

    virtual ~Device() {}
};

class Light : public Device {
    int brightnessLevel;
    string colorMode;

public:
    Light(string i, string n, string l, int b = 50, string c = "White") : Device(i, n, l), brightnessLevel(b), colorMode(c) {}

    void display() const override {
        Device::display();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
    float currentTemp, targetTemp;
    string mode;

public:
    Thermostat(string i, string n, string l, float c, float t, string m) : Device(i, n, l), currentTemp(c), targetTemp(t), mode(m) {}

    string getStatus() const {
        return "Current Temp: " + to_string(currentTemp) + "°C, Mode: " + mode;
    }
};

class SecurityCamera : public Device {
    string resolution;
    bool recordingStatus, nightVisionEnabled;

public:
    SecurityCamera(string i, string n, string l, string r = "1080p", bool nV = true) : Device(i, n, l), resolution(r), recordingStatus(false), nightVisionEnabled(nV) {}

    void turnOn() override {
        Device::turnOn();
        recordingStatus = true;
        cout << "Security Camera is now recording!\n";
    }
};

class SmartPlug : public Device {
    int powerConsumption, timerSetting;

public:
    SmartPlug(string i, string n, string l, int p, int t) : Device(i, n, l), powerConsumption(p), timerSetting(t) {}

    void turnOff() override {
        Device::turnOff();
        cout << "Smart Plug turned off. Power usage logged: " << powerConsumption << "W\n";
    }
};

int main() {
    Device* d1 = new Light("L01", "Living Room Light", "Living Room", 75, "Warm White");
    Device* d2 = new Thermostat("T01", "Home Thermostat", "Hallway", 24.0, 26.0, "Heating");
    Device* d3 = new SecurityCamera("C01", "Front Door Cam", "Entrance", "4K", true);
    Device* d4 = new SmartPlug("P01", "Smart Plug", "Kitchen", 120, 30);

    d1->turnOn();
    d2->turnOn();
    d3->turnOn();
    d4->turnOn();

    cout << "\nDisplaying Device Information:\n";
    d1->display();
    cout << "\n";
    d2->display();
    cout << "Status Info: " << static_cast<Thermostat*>(d2)->getStatus() << "\n\n";
    d3->display();
    cout << "\n";
    d4->display();
    cout << "\n";

    delete d1;
    delete d2;
    delete d3;
    delete d4;

    return 0;
}
