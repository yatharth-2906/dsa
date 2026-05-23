// Problem Statement: Given an integer array arr of size N, sorted in ascending order (with distinct values). 
// Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array.

// Input Format: arr = [4,5,6,7,0,1,2,3]

// Result: 0

// Explanation: Here, the element 0 is the minimum element in the array.

#include <iostream>
#include <vector>

using namespace std;

int peak_element(vector<int> &nums, int n)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (end - start) / 2 + start;
        int prev = (mid - 1 + n) % n, next = (mid + 1) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
        {
            return nums[mid];
        }
        else if (nums[end] <= nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return -1;
}

int main(void)
{
    vector<int> arr = {4, 5, 6, 7, 8, 0, 1, 2, 3};
    int n = arr.size();

    int k = peak_element(arr, n);

    // Time: O(log n) Space: O(1)
    cout << k << endl;

    return 0;
}