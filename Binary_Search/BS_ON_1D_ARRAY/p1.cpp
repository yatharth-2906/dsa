// Problem statement: You are given a sorted array of integers and a target, your task is to search for the target in the given array. Assume the given array does not contain any duplicate numbers.

// Input: arr = {3, 4, 6, 7, 9, 12, 16, 17} and target = 6.

// Output: 2 (index of element 6) {if not found return -1}

#include <iostream>
#include <vector>

using namespace std;

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
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int n = arr.size(), target = 6;

    int res = binary_search(arr, 0, n - 1, target);

    // Time: O(log n) Space: O(1)
    if (res == -1)
        cout << "The element " << target << " is not present in the array." << endl;
    else
        cout << "The element " << target << " is present in the array at index: " << res << endl;

    return 0;
}