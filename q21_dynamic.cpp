#include <iostream>
using namespace std;

class Matrix
{
    int n, m;
    int **arr;

    friend ostream &operator<<(ostream &, Matrix &);
    friend istream &operator>>(istream &, Matrix &);

public:
    Matrix(int a, int b)
    {
        n = a;
        m = b;
        arr = new int *[n];
        for (int i = 0; i < n; i++)
            arr[i] = new int[m];
    }
};

ostream &operator<<(ostream &out, Matrix &mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
            out << mat.arr[i][j] << " ";
        out << endl;
    }
    return out;
}

istream &operator>>(istream &in, Matrix &mat)
{
    for (int i = 0; i < mat.n; i++)
    {
        for (int j = 0; j < mat.m; j++)
            in >> mat.arr[i][j] ;
    }
    return in;
}

int main()
{
    Matrix m(2, 2);
    cin >> m;
    cout << m;
    return 0;
}