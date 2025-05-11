#include <iostream>
#include <exception>

class InvalidTemperatureException : public std::exception {};

template <typename T>
T convertToFahrenheit(T celsius) {
    if (celsius < static_cast<T>(-273.15)) {
        throw InvalidTemperatureException();
    }
    return (celsius * 9 / 5) + 32;
}

int main() {
    try {
        double temp = -300.0;
        std::cout << "Attempting to convert " << temp << "C...\n";
        double fahrenheit = convertToFahrenheit(temp);
        std::cout << "Fahrenheit: " << fahrenheit << "\n";
    }
    catch (const InvalidTemperatureException& e) {
        std::cout << "Invalid TemperatureException: " << e.what() << std::endl;
    }

    return 0;
}
