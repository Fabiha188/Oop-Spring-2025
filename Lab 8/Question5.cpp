#include <iostream>
using namespace std;

class MatrixHelper;

class Matrix2x2 {
private:
    int m11, m12, m21, m22;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0)
        : m11(a), m12(b), m21(c), m22(d) {}

    Matrix2x2 operator+(const Matrix2x2& other) {
        return Matrix2x2(m11 + other.m11, m12 + other.m12, m21 + other.m21, m22 + other.m22);
    }

    Matrix2x2 operator-(const Matrix2x2& other) {
        return Matrix2x2(m11 - other.m11, m12 - other.m12, m21 - other.m21, m22 - other.m22);
    }

    Matrix2x2 operator*(const Matrix2x2& other) {
        return Matrix2x2(
            m11 * other.m11 + m12 * other.m21, m11 * other.m12 + m12 * other.m22,
            m21 * other.m11 + m22 * other.m21, m21 * other.m12 + m22 * other.m22
        );
    }

    friend int determinant(const Matrix2x2& matrix);

    friend class MatrixHelper;

    friend ostream& operator<<(ostream& os, const Matrix2x2& matrix) {
        os << "[" << matrix.m11 << " " << matrix.m12 << "]\n"
           << "[" << matrix.m21 << " " << matrix.m22 << "]";
        return os;
    }
};

int determinant(const Matrix2x2& matrix) {
    return matrix.m11 * matrix.m22 - matrix.m12 * matrix.m21;
}

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int newValue) {
        if (row == 1 && col == 1) matrix.m11 = newValue;
        else if (row == 1 && col == 2) matrix.m12 = newValue;
        else if (row == 2 && col == 1) matrix.m21 = newValue;
        else if (row == 2 && col == 2) matrix.m22 = newValue;
        else cout << "Invalid position!" << endl;
    }
};

int main() {
    Matrix2x2 matrix1(1, 2, 3, 4);
    Matrix2x2 matrix2(5, 6, 7, 8);
    
    cout << "Matrix 1:\n" << matrix1 << "\n";
    cout << "Matrix 2:\n" << matrix2 << "\n";

    Matrix2x2 sum = matrix1 + matrix2;
    cout << "Matrix 1 + Matrix 2:\n" << sum << "\n";

    Matrix2x2 difference = matrix1 - matrix2;
    cout << "Matrix 1 - Matrix 2:\n" << difference << "\n";

    Matrix2x2 product = matrix1 * matrix2;
    cout << "Matrix 1 * Matrix 2:\n" << product << "\n";

    cout << "Determinant of Matrix 1: " << determinant(matrix1) << "\n";

    MatrixHelper helper;
    helper.updateElement(matrix1, 1, 1, 10);
    cout << "Updated Matrix 1:\n" << matrix1 << "\n";
    
    return 0;
}
