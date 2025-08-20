// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]

// Output: [4, -1, 2, 1 ]

#include <iostream>
#include <vector>

using namespace std;

long long print_max_subarray_sum(vector<int> &arr, int n)
{
    int start = 0, maxi = 0, maxj = 0;
    long long res = arr[0], sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];

        if (sum >= res)
        {
            res = sum;

            maxi = start;
            maxj = i;
        }

        if (sum < 0)
        {
            sum = 0;

            start = i + 1;
        }
    }

    for (int i = maxi; i <= maxj; i++)
        cout << arr[i] << " ";
    cout << endl;

    return res;
}

int main(void)
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    cout << print_max_subarray_sum(arr, n) << endl; // Time: O(n) Space: O(1)

    return 0;
}