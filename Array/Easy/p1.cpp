// Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not.
// If the array is sorted then return True, Else return False.

// Input: N = 5, array[] = {1,2,3,4,5}

// Output: True

#include <iostream>
#include <vector>

using namespace std;

string is_sorted(vector<int> arr, int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        if (arr[i] > arr[i + 1])
            return "False";
    }

    return "True";
}

int main(void)
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    cout << is_sorted(arr, n); // Time: O(n) Space: O(1)

    return 0;
}