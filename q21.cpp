#include <iostream>
using namespace std;

class Matrix
{

private:
    int n, m;
    int arr[100][100];
    int transposeArr[100][100];

public:
    friend Matrix operator+(Matrix m1, Matrix m2);
    friend Matrix operator-(Matrix m1, Matrix m2);
    friend Matrix operator*(Matrix m1, Matrix m2);
    friend ostream &operator<<(ostream &output, Matrix &mat);
    friend istream &operator>>(istream &input, Matrix &mat);

    Matrix() {}
    Matrix(int a, int b)
    {
        n = a;
        m = b;
    }

    void printMatrix()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printTranspose()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << transposeArr[i][j] << " ";
            }
            cout << endl;
        }
    }

    void inputMatrix()
    {
        cout << "Enter elements of matrix" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void transpose()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                transposeArr[j][i] = arr[i][j];
            }
        }
    }
};

ostream &operator<<(ostream &output, Matrix &mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
        {
            output << mat.arr[i][j] << " ";
        }
        output << endl;
    }
    return output;
}

istream &operator>>(istream &input, Matrix &mat)
{
    cout << "Enter elements of matrix" << endl;
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
        {
            input >> mat.arr[i][j];
        }
    }
    return input;
}

Matrix operator+(Matrix m1, Matrix m2)
{
    Matrix res;
    res.m = m1.m;
    res.n = m1.n;
    for (int i = 0; i < m1.n; i++)
    {
        for (int j = 0; j < m1.m; j++)
        {
            res.arr[i][j] = m1.arr[i][j] + m2.arr[i][j];
        }
    }
    return res;
};

Matrix operator-(Matrix m1, Matrix m2)
{
    Matrix res;
    res.m = m1.m;
    res.n = m1.n;
    for (int i = 0; i < m1.n; i++)
    {
        for (int j = 0; j < m1.m; j++)
        {
            res.arr[i][j] = m1.arr[i][j] - m2.arr[i][j];
        }
    }
    return res;
};

Matrix operator*(Matrix m1, Matrix m2)
{
    Matrix res;
    res.n = m1.n;
    res.m = m2.m;
    int sum;
    // n -> rows
    // m -> cols
    for (int i = 0; i < m1.n; i++)
    {
        for (int j = 0; j < m2.m; j++)
        {
            sum = 0;
            for (int k = 0; k < m1.m; k++)
            {
                sum += m1.arr[i][k] * m2.arr[k][j];
            }
            res.arr[i][j] = sum;
        }
    }
    return res;
};

int main()
{
    Matrix result;
    char choice;

    int n1, m1, m2, n2;
    cout << "Enter dimension of matrix 1 : ";
    cin >> n1 >> m1;

    cout << "Enter dimension of matrix 2 : ";
    cin >> n2 >> m2;

    if (n1 <= 0 || m1 <= 0 || m2 <= 0 || n2 <= 0)
    {
        cout << "Matrix can not have any negative or zero order !!!" << endl;
        exit(1);
    }

    Matrix A(n1, m1), B(n2, m2);

    bool isAddOrSubtract = (n1 == n2) && (m1 == m2);
    bool isMultiply = m1 == n2;

    cout << "For matrix 1" << endl;
    cin >> A;
    cout << "For matrix 2" << endl;
    cin >> B;

    // Calculate transposes
    A.transpose();
    B.transpose();

    while (true)
    {
        cout << "-------MENU-------" << endl;
        cout << "1.Print The Matrices" << endl;
        cout << "2.Add The Matrices" << endl;
        cout << "3.Subtract The Matrices" << endl;
        cout << "4.Multiply The Matrices" << endl;
        cout << "5.Transpose of matrices" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice" << endl;
        cin >> choice;

        if (choice == '6')
        {
            cout << "Exiting the Program..." << endl;
            break;
        }

        switch (choice)
        {
        case '1':
            cout << "Matrix A" << endl;
            cout << A;
            cout << "Matrix B" << endl;
            cout << B;
            break;

        case '2':

            if (isAddOrSubtract)
            {
                result = A + B;
                cout << "Addition Result" << endl;
                cout << result;
            }
            else
            {
                cout << "A and B can't be added" << endl;
            }

            break;

        case '3':

            if (isAddOrSubtract)
            {
                result = A - B;
                cout << "Subtraction Result" << endl;
                cout << result;
            }
            else
            {
                cout << "A and B can't be subtracted" << endl;
            }

            break;
        case '4':

            if (isMultiply)
            {
                result = A * B;
                cout << "Multiplication Result" << endl;
                cout << result;
            }
            else
            {
                cout << "A and B can't be multiplied" << endl;
            }
            break;

        case '5':
            cout << "Transpose of A" << endl;
            A.printTranspose();

            cout << "Transpose of B" << endl;
            B.printTranspose();

            break;

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}