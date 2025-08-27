// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

// Input: N = 5, array[] = {1,3,2,3,1}

// Output: 2 

// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

#include <iostream>
#include <vector>

using namespace std;

void count_reverse_pairs_on_two_sorted_arrays(vector<int> &arr, int start, int mid, int end, int &res){
    int i=start, j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i] <= 2*arr[j])
            i++;
        else{
            res = res + (mid-i+1);
            j++;
        }
    }
}

void merge(vector<int> &arr, int start, int mid, int end, int &res){
    count_reverse_pairs_on_two_sorted_arrays(arr, start, mid, end, res);

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

int numberOfReversePairs(vector<int> arr) {
    int n = arr.size(), res = 0;

    merge_sort(arr, 0, n-1, res);

    return res;
}

int main(void)
{
    vector<int> arr = {1,3,2,3,1};

    cout<<"The number of reverse pairs are: "<<numberOfReversePairs(arr); // Time: O(n logn) Space: O(n)

    return 0;
}