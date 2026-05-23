// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.

// Input Format: arr = [4,5,6,7,0,1,2,3], k = 2

// Result: 6

// Explanation: Here, the target is 0. We can see that 0 is present in the given rotated sorted array, nums. Thus, we get output as 4, which is the index at which 0 is present in the array.

#include <iostream>
#include <vector>

using namespace std;

int peak_element(vector<int> &arr, int n)
{
    if (n == 1)
        return 0;

    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
        if (arr[mid] > arr[prev] && arr[mid] > arr[next])
            return mid;

        else if (arr[left] < arr[right])
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int binary_search(vector<int> &arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int main(void)
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int n = arr.size(), x = 2;

    int k = peak_element(arr, n);
    int res1 = binary_search(arr, 0, k, x), res2 = binary_search(arr, k + 1, n - 1, x);

    // Time: O(log n) Space: O(1)
    if (res1 != -1)
        cout << res1 << endl;
    else
        cout << res2 << endl;

    return 0;
}