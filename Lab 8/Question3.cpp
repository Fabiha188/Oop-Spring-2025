#include <iostream>
using namespace std;

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double xCoord = 0, double yCoord = 0) {
        x = xCoord;
        y = yCoord;
    }

    Vector2D operator+(const Vector2D& other) {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) {
        return Vector2D(x * scalar, y * scalar);
    }

    friend double dotProduct(const Vector2D& vector1, const Vector2D& vector2);

    friend ostream& operator<<(ostream& output, const Vector2D& vector) {
        output << "(" << vector.x << ", " << vector.y << ")";
        return output;
    }
};

double dotProduct(const Vector2D& vector1, const Vector2D& vector2) {
    return vector1.x * vector2.x + vector1.y * vector2.y;
}

int main() {
    Vector2D vector1(3, 4);
    Vector2D vector2(1, 2);

    Vector2D sum = vector1 + vector2;
    Vector2D difference = vector1 - vector2;
    Vector2D scaled = vector1 * 2;

    cout << "Vector 1: " << vector1 << "\n";
    cout << "Vector 2: " << vector2 << "\n";
    cout << "Sum: " << sum << "\n";
    cout << "Difference: " << difference << "\n";
    cout << "Scaled (Vector 1 * 2): " << scaled << "\n";
    cout << "Dot Product: " << dotProduct(vector1, vector2) << "\n";

    return 0;
}
