// Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort).
// What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Input: N = 5, array[] = {5,3,2,1,4}

// Result: 7

// Explanation: There are 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1) and we have left 2 pairs (2,4) and (1,4) as both are not satisfy our condition.

#include <iostream>
#include <vector>

using namespace std;

void count_inverions_on_two_sorted_arrays(vector<int> &arr, int start, int mid, int end, int &res){
    int i=start, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i] <= arr[j])
            i++;
        else{
            res = res + (mid-i+1);
            j++;
        }
    }
}

void merge(vector<int> &arr, int start, int mid, int end, int &res){
    count_inverions_on_two_sorted_arrays(arr, start, mid, end, res);

    vector<int> temp(end-start+1, 0);

    int i=start, j=mid+1, k=0;
    while(i<=mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++; k++;
        }

        else{
            temp[k] = arr[j];
            j++; k++;
        }
    }

    while(i<=mid){
        temp[k] = arr[i];
        i++; k++;
    }

    while(j<=end){
        temp[k] = arr[j];
        j++; k++;
    }

    for(k=start; k<=end; k++)
        arr[k] = temp[k-start];
}

void merge_sort(vector<int> &arr, int start, int end, int &res){
    if(start >= end)
        return;
    
    int mid = (end-start)/2 + start;

    merge_sort(arr, start, mid, res);
    merge_sort(arr, mid+1, end, res);
    merge(arr, start, mid, end, res);
}

int numberOfInversions(vector<int> arr) {
    int n = arr.size(), res = 0;

    merge_sort(arr, 0, n-1, res);

    return res;
}

int main(void)
{
    vector<int> arr = {5,3,2,1,4};

    cout<<"The number of inversions are: "<<numberOfInversions(arr); // Time: O(n logn) Space: O(n)

    return 0;
}