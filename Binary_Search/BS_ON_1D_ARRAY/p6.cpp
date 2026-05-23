// Given a sorted array of N integers, write a program to find the frequency(occurance) of the target key.

// Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}

// Output: 3

#include <iostream>
#include <vector>

using namespace std;

int first_occurance(vector<int> &arr, int left, int right, int x)
{
    int res = -1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] == x)
        {
            res = mid;
            right = mid - 1;
        }

        else if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return res;
}

int last_occurance(vector<int> &arr, int left, int right, int x)
{
    int res = -1;
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;

        if (arr[mid] == x)
        {
            res = mid;
            left = mid + 1;
        }

        else if (arr[mid] < x)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return res;
}

int main(void)
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int n = arr.size(), x = 13;

    int res1 = first_occurance(arr, 0, n - 1, x);
    int res2 = last_occurance(arr, 0, n - 1, x);
    int count = (res2 - res1) + 1;

    cout << "Count of " << x << ": " << count << endl; // Time: O(log n) Space: O(1)

    return 0;
}