// Problem Statement: Given a non-empty array of integers arr, every element appears twice except for one. Find that single one.

// Input Format: arr[] = {4,1,2,1,2}

// Result: 4

#include <iostream>
#include <vector>

using namespace std;

int findSingleElement(vector<int> &arr, int n)
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }

    return res;
}

int main(void)
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int n = arr.size();

    cout << findSingleElement(arr, n); // Time: O(n) Space: O(1)

    return 0;
}