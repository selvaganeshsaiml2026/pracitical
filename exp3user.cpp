
#include <iostream>
#include <cassert>
using namespace std;

class Matrix
{
private:
    int data[2][2];

public:
    Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
    {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix operator+(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                result.data[i][j] = data[i][j] + m.data[i][j];

        return result;
    }

    Matrix operator*(const Matrix &m)
    {
        Matrix result;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                result.data[i][j] = 0;

                for (int k = 0; k < 2; k++)
                    result.data[i][j] += data[i][k] * m.data[k][j];
            }
        }

        return result;
    }

    int* operator[](int index)
    {
        return data[index];
    }

    friend ostream& operator<<(ostream &out, const Matrix &m)
    {
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                out << m.data[i][j] << " ";

            out << endl;
        }

        return out;
    }
};

int main()
{
    int a, b, c, d;

    // Get input for Matrix A
    cout << "Enter elements of Matrix A (2x2):" << endl;

    cin >> a >> b >> c >> d;

    Matrix A(a, b, c, d);

    // Get input for Matrix B
    cout << "Enter elements of Matrix B (2x2):" << endl;

    int e, f, g, h;

    cin >> e >> f >> g >> h;

    Matrix B(e, f, g, h);

    // Perform matrix operations
    Matrix sum = A + B;
    Matrix product = A * B;

    // Display matrices
    cout << "\nMatrix A:" << endl;
    cout << A;

    cout << "Matrix B:" << endl;
    cout << B;

    cout << "Addition of Matrices:" << endl;
    cout << sum;

    cout << "Multiplication of Matrices:" << endl;
    cout << product;

    cout << "Matrix operations completed successfully." << endl;

    return 0;
}
