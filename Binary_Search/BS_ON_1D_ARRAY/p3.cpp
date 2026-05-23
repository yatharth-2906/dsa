// Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

// Input Format: N = 4, arr[] = {1,2,2,3}, x = 2

// Result: 3

// Explanation: Index 3 is the smallest index such that arr[3] > x.

#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> &arr, int left, int right, int x)
{
    int res = right + 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] > x)
        {
            res = mid;
            right = mid - 1;
        }

        else
            left = mid + 1;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1, 2, 2, 3};
    int n = arr.size(), x = 2;

    int res = upper_bound(arr, 0, n - 1, x); // Time: O(log n) Space: O(1)
    cout << "The upper bound of " << x << " is: " << res << endl;

    return 0;
}