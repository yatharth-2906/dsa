// Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: arr = [2,0,2,1,1,0]

// Output: [0,0,1,1,2,2]

#include <iostream>
#include <vector>

using namespace std;

void sort_dnf(vector<int> &arr, int n)
{
    int left = 0, mid = 0, right = n - 1;

    while (mid <= right)
    {
        if (arr[mid] == 0)
        {
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        }

        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[right]);
            right--;
        }

        else
            mid++;
    }
}

int main(void)
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    int n = arr.size();

    sort_dnf(arr, n); // Time: O(n) Space: O(1)

    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}