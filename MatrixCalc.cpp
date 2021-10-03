#include <iostream>

using namespace std;

class MatrixCalc {
public:
    int** matrix = NULL;
    int n, m;
    void fillMatrix();
    MatrixCalc* addMatrix(MatrixCalc* matrix1, MatrixCalc* matrix2);

    MatrixCalc(int n, int m) {
        if (n <= 0 || m <= 0)
            return;
        this->n = n;
        this->m = m;
        matrix = new int* [n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
        }
    }

    MatrixCalc(int n, int m, int** matrix) {
        if (n <= 0 || m <= 0)
            return;
        if (matrix == NULL)
            return;
        this->n = n;
        this->m = m;
        this->matrix = new int* [n];
        for (int i = 0; i < n; i++)
        {
            this->matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                this->matrix[i][j] = matrix[i][j];
            }
        }
    }
};

void MatrixCalc::fillMatrix() {
    if (n <= 0 || m <= 0)
        return;
    int number;
    for (int i = 0; i < this->n; i++)
    {
        this->matrix[i] = new int[this->m];
        for (int j = 0; j < this->m; j++)
        {
            cin >> number;
            this->matrix[i][j] = number;
        }
    }
}

MatrixCalc* MatrixCalc::addMatrix(MatrixCalc* matrix1, MatrixCalc* matrix2) {
    if (matrix1->n <= 0 || matrix2->n <= 0 || matrix1->m <= 0 || matrix2->m <= 0)
        return NULL;
    if ((matrix1->n != matrix2->n) || (matrix1->m != matrix2->m))
        return NULL;
    MatrixCalc* result = new MatrixCalc(matrix1->n, matrix1->m);
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->m; j++)
        {
            result->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
        }
    }
    return result;
}

int main()
{
   
}