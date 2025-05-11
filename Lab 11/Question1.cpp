#include <iostream>
#include <exception>
#include <sstream>
#include <cstring>

class DimensionMismatchException : public std::exception {
private:
    char message[100];

public:
    DimensionMismatchException(int r1, int c1, int r2, int c2) {
        std::ostringstream oss;
        oss << "Matrix Dimensions are different so not possible ("
            << r1 << "x" << c1 << " vs " << r2 << "x" << c2 << ")";
        std::string msg = oss.str();
        std::strncpy(message, msg.c_str(), sizeof(message));
        message[sizeof(message) - 1] = '\0';
    }

    const char* what() const noexcept override {
        return message;
    }
};

template <typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]{};
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                std::cout << data[i][j] << " ";
            std::cout << '\n';
        }
    }
};

int main() {
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;
        C.display();
    }
    catch (const DimensionMismatchException& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
