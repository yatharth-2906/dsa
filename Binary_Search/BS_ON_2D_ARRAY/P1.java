// Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. 
// All the rows are sorted in ascending order. Your task is to find the index of the row with the maximum number of ones. 
// If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1

// Example:
// Input: n = 3, m = 3, 
// mat[] = 
// 1 1 1
// 0 0 1
// 0 0 0
// Result: 0

public class P1 {
    public static int findFirstOccurance(int[] arr, int n, int value){
        int start = 0, end = n-1, res = -1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(arr[mid] == value){
                res = mid;
                end = mid-1;
            } else if(arr[mid] < value){
                start = mid+1;
            } else{
                end = mid-1;
            }
        }

        return res;
    }

    public static int findLastOccurance(int[] arr, int n, int value){
        int start = 0, end = n-1, res = -1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(arr[mid] == value){
                res = mid;
                start = mid+1;
            } else if(arr[mid] < value){
                start = mid+1;
            } else{
                end = mid-1;
            }
        }

        return res;
    }

    public static int countOfOnesInRow(int[] arr, int n){
        int firstOccurance = findFirstOccurance(arr, n, 1);
        if(firstOccurance == -1) return 0;
        int lastOccurance = findLastOccurance(arr, n, 1);
        return lastOccurance - firstOccurance + 1;
    }

    public static int findRowWithMaxOnes(int[][] matrix){
        int n = matrix.length, m = matrix[0].length;
        
        int res = -1, count = 0;
        for(int i=0; i<n; i++){
            int temp = countOfOnesInRow(matrix[i], m);

            if(temp>count){
                count = temp;
                res = i;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};

        int res = findRowWithMaxOnes(matrix); //Time: O(n * log n) and Space: O(1)
        System.out.println("The row with max. number of ones is: "+res);
    }
}
