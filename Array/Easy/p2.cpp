// Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that each unique element appears only once. The relative order of the elements should be kept the same.
// If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. It does not matter what you leave beyond the first k elements.

// Input: nums = [0,0,1,1,1,2,2,3,3,4]

// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int> &arr, int n)
{
    int i = 0, j = 0, c = 0;

    while (j < n)
    {
        if (arr[i] == arr[j])
        {
            j++;
        }

        else
        {
            arr[c] = arr[i];
            i = j;
            c++;
        }
    }  
    arr[c++] = arr[i];

    return c;
}

int main(void)
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n = arr.size();

    int k =  remove_duplicates(arr, n); // Time: O(n) Space: O(1)

    cout << "Unique array: \n";
    for(int i=0; i<k; i++)
        cout << arr[i] << " ";

    return 0;
}