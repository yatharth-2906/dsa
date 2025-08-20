// Problem Statement: Given an integer array arr, find the contiguous subarray (containing at least one number) which has the largest sum and returns its sum and prints the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]

// Output: 6

#include <iostream>
#include <vector>

using namespace std;

long long kadane_max_subarray_sum(vector<int> &arr, int n)
{
    long long res = arr[0], sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        res = max(res, sum);

        if (sum < 0)
            sum = 0;
    }

    return res;
}

int kadane_min_subarray_sum(vector<int> &arr, int n)
{
    int res = arr[0], sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        res = min(res, sum);

        if (sum > 0)
            sum = 0;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();

    cout << kadane_max_subarray_sum(arr, n) << endl; // Time: O(n) Space: O(1)
    cout << kadane_min_subarray_sum(arr, n) << endl; // Time: O(n) Space: O(1)

    return 0;
}