// Input Format: N = 3

// Result:
// 3 3 3 3 3
// 3 2 2 2 3
// 3 2 1 2 3
// 3 2 2 2 3
// 3 3 3 3 3

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int matrix_size = 2*n - 1;
    vector<vector<int>> matrix(matrix_size, vector<int>(matrix_size, -1));

    int row1 = 0, row2 = matrix_size - 1;
    int col1 = 0, col2 = matrix_size - 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = col1; j <= col2; j++)
        {
            matrix[row1][j] = n - i;
            matrix[row2][j] = n - i;
        }

        for (int k = row1; k <= row2; k++)
        {
            matrix[k][col1] = n - i;
            matrix[k][col2] = n - i;
        }

        row1++; row2--;
        col1++; col2--;
    }

    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            cout << matrix[i][j]<< " ";
        }
        cout << endl;
    }
}