// Problem Statement: Given an integer N, return the first N of Pascal's triangle. (N>=1)

// Input Format: N = 5

// Result: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate_pascal_triangle(int n)
{
    vector<vector<int>> result;
    result.push_back({1});

    for (int i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            result.push_back({1, 1});
        }

        else
        {
            int n = i - 1;

            vector<int> temp;
            temp.push_back(1);

            for (int j = 0; j <= n - 2; j++)
                temp.push_back(result[i - 2][j] + result[i - 2][j + 1]);

            temp.push_back(1);
            result.push_back(temp);
        }
    }

    return result;
}

void print_generated_pascal_triangle(vector<vector<int>> result)
{
    int n = result.size();

    for (int i = 0; i < n; i++)
    {
        int m = result[i].size();

        for (int k = 0; k < result[n - 1].size() - m; k++)
            cout << " ";

        for (int j = 0; j < m; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    int n = 5;

    vector<vector<int>> result = generate_pascal_triangle(n); // Time: O(n) Space: O(n)
    print_generated_pascal_triangle(result);

    return 0;
}