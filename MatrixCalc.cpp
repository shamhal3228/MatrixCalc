#include <iostream>

using namespace std;

class MatrixCalc {
public:
    int** matrix = NULL;
    int n, m;
    void fillMatrix();

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

int main()
{
   
}