// Problem Statement: Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False.

// Input Format: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3

// Result: True

// Explanation: The element 3 is present in the array. So, the answer is True.

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &arr, int n, int x)
{
    if (n == 1)
        return 0;

    if (arr[0] == x)
        return 0;

    if (arr[n - 1] == x)
        return n - 1;

    int left = 1, right = n - 2;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        int prev = arr[mid + 1], next = arr[mid - 1];
        if (arr[mid] == x)
            return true;

        else if (arr[left] == arr[right])
        {
            left++;
            right--;
        }

        else if (arr[left] <= arr[mid])
        {
            if (arr[left] <= x && x <= arr[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        else
        {
            if (arr[mid] <= x && x <= arr[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return false;
}

int main(void)
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = arr.size(), x = 3;

    bool res = search(arr, n, x);

    // Time: O(log n) Space: O(1)
    cout << res << endl;

    return 0;
}