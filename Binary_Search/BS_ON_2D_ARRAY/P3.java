// Problem Statement: Given a 0-indexed n x m matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] 
// and return the array [i, j]. A peak element in a 2D grid is an element that is strictly greater than all of its adjacent 
// neighbours to the left, right, top, and bottom. Assume that the entire matrix is surrounded by an outer perimeter with the 
// value -1 in each cell.

// Example:
// Input: mat = [[5, 10, 8], [4, 25, 7], [3, 9, 6]]
// Output: [1, 1]

public class P3 {
    public static int findMaxInColumn(int[][] mat, int n, int m, int col){
        int res = 0, max = mat[0][col];

        for(int i=1; i<n; i++){
            if(mat[i][col] > max){
                res = i;
                max = mat[i][col];
            }
        }

        return res;
    }

    public static int[] findPeakGrid(int[][] mat) {
        int n = mat.length, m = mat[0].length;

        int start = 0, end = m-1;
        while(start<=end){
            int mid = (end-start)/2 + start;

            int elementRow = findMaxInColumn(mat, n, m, mid);
            int left = (mid-1>=0)?mat[elementRow][mid-1]:-1;
            int right = (mid+1<m)?mat[elementRow][mid+1]:-1;

            if(mat[elementRow][mid]>left && mat[elementRow][mid]>right){
                return new int[]{elementRow, mid};
            } else if(left>right){
                end = mid-1;
            } else{
                start = mid+1;
            }
        }

        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[][] matrix = {{5, 10, 8},{4, 25, 7},{3,6,9}};

        int[] res = findPeakGrid(matrix); //Time: O(n * log m) and Space: O(1)
        System.out.println(res[0] + " " + res[1]);
    }
}
