// Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote the number of rows and 
// columns, respectively. The elements of each row are sorted in non-decreasing order. Moreover, the first element of a row 
// \is greater than the last element of the previous row (if it exists). You are given an integer ‘target’, and your task is 
// to find if it exists in the given 'mat' or not.

// Example:
// Input :mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
// Output :True.

public class P2 {
    public static int[] findInMatrix(int[][] matrix, int value){
        int n = matrix.length, m = matrix[0].length;

        int row_it = 0, col_it = m-1;
        while(row_it<n && col_it>=0){
            if(matrix[row_it][col_it] == value){
                return new int[]{row_it, col_it};
            } else if(matrix[row_it][col_it] < value){
                row_it++;
            } else{
                col_it--;
            }
        }

        return new int[] {-1, -1};
    }

    public static void main(String[] args) {
        int[][] matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
        int value = 5;

        int[] res = findInMatrix(matrix, value); //Time: O(n + m) and Space: O(1)
        System.out.println(res[0] + " " + res[1]);
    }
}
