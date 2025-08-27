// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers. If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

// Input format: Arr[] = {1,3,2}

// Output: Arr[] = {2,1,3}

// Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,1,3} , {2,3,1} , {3,1,2} , {3,2,1}}. So, the next permutation just after {1,3,2} is {2,1,3}.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int next_greatest(vector<int> arr, int start, int end, int k)
{
    int res = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] > arr[k] && arr[i] < arr[res])
            res = i;
    }

    return res;
}

void array_next_permutation(vector<int> &arr, int n)
{
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            int swap_index = next_greatest(arr, i + 1, n - 1, i);
            swap(arr[i], arr[swap_index]);
            reverse(arr.begin() + (i + 1), arr.end());
            return;
        }
    }

    reverse(arr.begin(), arr.end());
}

int main(void)
{
    vector<int> arr = {2, 1, 3};
    int n = arr.size();

    array_next_permutation(arr, n); // Time: O(n) Space: O(1)

    cout << "Modified Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}