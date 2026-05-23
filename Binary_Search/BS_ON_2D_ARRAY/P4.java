// Problem Statement: Given a row-wise sorted matrix of size M*N, where M is no. of rows and N is no. of columns, find the 
// median in the given matrix. Note: M*N is odd.

// Example:
// Input: M = 3, N = 3, matrix[][] =
// 1 4 9 
// 2 5 6
// 3 8 7
// Output: 5

public class P4 {
        public static int lesser_values_row(int[] arr, int n, int t){
        int res = n;

        int start = 0, end = n-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            if(arr[mid] > t){
                res = mid;
                end = mid-1;
            } else{
                start = mid+1;
            }
        }

        return res;
    }

    public static int lesser_values_matrix(int[][] matrix, int n, int m, int t){
        int res = 0;

        for(int i=0; i<n; i++){
            res += lesser_values_row(matrix[i], m, t);
        }

        return res;
    }

    // Rows:n and Columns:m
    public static int findMedian(int[][] matrix, int n, int m) {
        int k = (n*m + 1)/2;

        int start = matrix[0][0], end = matrix[0][m-1];
        for(int i=0; i<n; i++){
            start = Math.min(start, matrix[i][0]);
            end = Math.max(end, matrix[i][m-1]);
        }

        while(start<end){
            int mid = (end-start)/2 + start;

            if(lesser_values_matrix(matrix, n, m, mid) < k){
                start = mid+1;
            } else{
                end = mid;
            }
        }

        return start;
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,4,9},{2,5,6},{3,8,7}};
        int n = matrix.length, m = matrix[0].length;

        int res = findMedian(matrix, n, m); //Time: O(n * log m * log(max-min)) and Space: O(1)
        System.out.println(res);
    }
}
