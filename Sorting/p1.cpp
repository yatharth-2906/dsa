// Problem Statement: Given an array of N integers, write a program to implement the Selection Sorting algorithm.

// Input: N = 6, array[] = {13,46,24,52,20,9}

// Output: 9,13,20,24,46,52

#include <iostream> 
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int temp = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[temp])
                temp = j;
        }
        
        swap(arr[i], arr[temp]);
    }
}

int main(void) {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();

    selectionSort(arr, n); // Time: O(n^2) Space: O(1)

    cout << "Sorted array: \n";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";

    return 0;
}