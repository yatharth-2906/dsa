// Problem Statement:  Given an array of n integers, sort the array using the Quicksort method.

// Input:  N = 5  , Arr[] = {4,1,7,9,3}

// Output: 1 3 4 7 9

#include <iostream>
#include <vector>

using namespace std;

int pivot_partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int pivot_index = start;

    for (int i = start+1; i <= end; i++)
        if (arr[i] < pivot)
            pivot_index++;

    swap(arr[start], arr[pivot_index]);

    int left = start, right = end;

    while (left < pivot_index && right > pivot_index)
    {
        if (arr[left] >= pivot)
        {
            swap(arr[left], arr[right]);
            right--;
        }

        else
            left++;
    }

    return pivot_index;
}

void quick_sort(vector<int> &arr, int start, int end)
{
    if (start >= end)
        return;

    int pivot_index = pivot_partition(arr, start, end);
    quick_sort(arr, start, pivot_index - 1);
    quick_sort(arr, pivot_index + 1, end);
}

int main(void)
{
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    quick_sort(arr, 0, n - 1); // Time: O(log n) Space: O(1)

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}