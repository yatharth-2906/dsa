// Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceil of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceil of x is the smallest element in the array greater than or equal to x.

// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5

// Result: 4 7

// Explanation: The floor of 5 in the array is 4, and the ceil of 5 in the array is 7.

#include <iostream>
#include <vector>

using namespace std;

int find_floor(vector<int> &arr, int left, int right, int x)
{
    int res = -1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] <= x){
            res = arr[mid];
            left = mid+1;
        }

        else
            right = mid-1;
    }

    return res;
}

int find_ceil(vector<int> &arr, int left, int right, int x)
{
    int res = -1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] >= x){
            res = arr[mid];
            right = mid-1;
        }

        else
            left = mid+1;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int n = arr.size(), x = 5;

    int floor = find_floor(arr, 0, n - 1, x);
    int ceil = find_ceil(arr, 0, n - 1, x);

    // Time: O(log n) Space: O(1)
    cout<<"Floor: "<<floor<<endl;
    cout<<"Ceil: "<<ceil<<endl;


    return 0;
}