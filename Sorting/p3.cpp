// Problem Statement: Given an array of N integers, write a program to implement the Insertion sorting algorithm.

// Input: N = 6, array[] = {13,46,24,52,20,9}

// Output: 9,13,20,24,46,52

#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &arr, int n) {
    for(int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

int main(void){
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();

    insertion_sort(arr, n); // Time: O(n^2) Space: O(1)

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}