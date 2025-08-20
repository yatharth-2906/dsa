// Problem Statement: Given an array of N integers, write a program to implement the Bubble Sorting algorithm.

// Input: N = 6, array[] = {13,46,24,52,20,9}

// Output: 9,13,20,24,46,52

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &arr, int n){
    for(int i=n-1; i>=0; i--){
        bool swapped = false;
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false)
            return;
    }
}

int main(void){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    bubble_sort(arr, n); // Time: O(n^2) Space: O(1)

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}