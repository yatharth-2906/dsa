// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]

// Output: [[1,0,1],[0,0,0],[1,0,1]]

#include <iostream>
#include <vector>

using namespace std;

void set_zeroes(vector<vector<int>> &matrix, int n, int m)
{
    bool firstRowZero = false, firstColZero = false;

    // Check if first row has any zeros
    for (int j = 0; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if first col has any zeros
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Use first row and first col as markers
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out cells based on markers
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out first row if needed
    if (firstRowZero)
    {
        for (int j = 0; j < m; j++)
            matrix[0][j] = 0;
    }

    // Zero out first col if needed
    if (firstColZero)
    {
        for (int i = 0; i < n; i++)
            matrix[i][0] = 0;
    }
}

int main(void)
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size(), m = matrix[0].size();

    set_zeroes(matrix, n, m);

    cout << "Modified Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}