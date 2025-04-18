#include <iostream>
using namespace std;


class WeatherSensor {
public:
    virtual void readData() = 0;
    virtual void displayReport() = 0;
    virtual ~WeatherSensor() {}
};


class Thermometer : public WeatherSensor {
private:
    float temperature;

public:
    Thermometer() {
        temperature = 0.0;
    }

    void readData() {
       
        temperature = 26.5;
    }

    void displayReport() {
        cout << "=== Thermometer Report ===\n";
        cout << "Temperature: " << temperature << " °C\n";
    }
};


class Barometer : public WeatherSensor {
private:
    float pressure;

public:
    Barometer() {
        pressure = 0.0;
    }

    void readData() {
       
        pressure = 1005.2;
    }

    void displayReport() {
        cout << "=== Barometer Report ===\n";
        cout << "Pressure: " << pressure << " hPa\n";
    }
};

int main() {
    WeatherSensor* T= new Thermometer();
    WeatherSensor* B = new Barometer();

    T->readData();
    T->displayReport();

    cout << "-----------------------------\n";

    B->readData();
    B->displayReport();

  
    delete T;
    delete B;

    return 0;
}
