// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Input: [[1,2,3],[4,5,6],[7,8,9]]

// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void transpose(vector<vector<int>> &matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i <= j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void reverse_rows(vector<vector<int>> &matrix, int n, int m)
{
    for(int i=0; i<n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}

int main(void)
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = matrix.size(), m = matrix[0].size();

    transpose(matrix, n, m);
    reverse_rows(matrix, n, m);

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