// Problem Statement: You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.
// If the value is present in the array, then return its index. Otherwise, determine the index where it would be inserted in the array while maintaining the sorted order.

// Input Format: arr[] = {1,2,4,7}, x = 6

// Result: 3

// Explanation: 6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), the array will still be sorted. {1,2,4,6,7}.

#include <iostream>
#include <vector>

using namespace std;

int insert_position(vector<int> &arr, int left, int right, int x)
{
    int res = right + 1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] >= x){
            res = mid;
            right = mid-1;
        }

        else
            left = mid+1;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {1,2,4,7};
    int n = arr.size(), x = 6;

    int res = insert_position(arr, 0, n - 1, x); // Time: O(log n) Space: O(1)
    cout << "The insert position of " << x << " is: " << res << endl;

    return 0;
}