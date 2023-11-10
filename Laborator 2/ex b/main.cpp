#include <iostream>
using namespace std;

class Matrix {
private:
    long* data;
    int rows;
    int cols;

public:

Matrix() {
    data = nullptr; //indicator special in C++ care semnifica un pointer nul sau inexistent.
    rows = 0;
    cols = 0;
}

Matrix(int n) {
    rows = n;
    cols = n;
    try {
        data = new long[n*n];
    } catch (bad_alloc &e) { //clasă de excepții atunci când nu poate aloca spațiu de memorie cerut.
        cerr << "Eroare: Alocarea memoriei a esuat (" << e.what() << ")" << endl; // iesirea standart de erori
        rows = cols = 0;                                                          // metodă returnează un șir de caractere
        data = nullptr;                                                           //care conține o descriere a excepție

    }
    for (int i = 0; i < n*n; i++) {
        data[i] = 0;
    }
}

Matrix(int r, int c) {
    rows = r;
    cols = c;
    try {
        data = new long[r*c];
    } catch (bad_alloc& e) {
        cerr << "Eroare: Alocarea memoriei a esuat (" << e.what() << ")" << endl;
        rows = cols = 0;
        data = nullptr;
    }
    for (int i = 0; i < r*c; i++) {
        data[i] = 0;
    }
}


    ~Matrix() {

        delete[] data;
    }

    long &operator()(int i, int j) {
        return data[i * cols + j];
    }

    const long &operator()(int i, int j) const {
        return data[i * cols + j];
    }

    Matrix operator+( Matrix& other)  {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Dimensiunile matricelor nu sunt compatibile pentru adunare");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Matrix operator-( Matrix& other)  {
        if (rows != other.rows || cols != other.cols) {
            throw invalid_argument("Dimensiunile matricelor nu sunt compatibile pentru scadere");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Matrix operator*( Matrix& other)  {
        if (cols != other.rows) {
            throw invalid_argument("Dimensiunile matricelor nu sunt compatibile pentru inmultire");
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result(i, j) += data[i * cols + k] * other(k, j);
                }
            }
        }
        return result;
    }

    Matrix operator*(long scalar)  {
        Matrix result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    void display()  {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i * cols + j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int codul_erorii = 0;

    try {
        Matrix A(2, 2);
        Matrix B(2, 2);

        A(0, 0) = 1;
        A(0, 1) = 2;
        A(1, 0) = 3;
        A(1, 1) = 4;

        B(0, 0) = 5;
        B(0, 1) = 6;
        B(1, 0) = 7;
        B(1, 1) = 8;

        cout << "Matrix A:\n";
        A.display();

        cout << "\nMatrix B:\n";
        B.display();

        Matrix C = A + B;
        cout << "\nMatrix 1 (A + B):\n";
        C.display();

        Matrix D = A - B;
        cout << "\nMatrix 2 (A - B):\n";
        D.display();

        Matrix E = A * B;
        cout << "\nMatrix 3 (A * B):\n";
        E.display();

        Matrix F = B * 2;
        cout << "\nMatrix 4 (A * 2):\n";
        F.display();

    } catch ( exception& e) {
        cerr << "Eroare: " << e.what() << endl;
        codul_erorii = 10;
    }

    return codul_erorii;
}
