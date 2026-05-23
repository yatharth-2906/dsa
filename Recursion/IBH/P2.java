public class P2 {
    public static void print_array(int[] arr, int start, int end){
        if(start>end || end>=arr.length){
            return;
        }

        print_array(arr, start+1, end);
        System.out.print(arr[start] + " ");
    }

    public static void adjust_element(int[] arr, int i, int temp){
        while(i>=0 && arr[i]<temp){
            arr[i+1] = arr[i];
            i--;
        }

        arr[i+1] = temp;    
    }

    public static void sort_array(int[] arr, int it){
        if(it<=0){
            return;
        }

        sort_array(arr, it-1);
        adjust_element(arr, it-1, arr[it]);
    }

    public static void main(String[] args) {
        int[] arr = {2,3,7,6,4,5,4,9};

        print_array(arr, 0, arr.length-1);
        System.out.println();
        sort_array(arr, arr.length-1);
        print_array(arr, 0, arr.length-1);
    }
}
