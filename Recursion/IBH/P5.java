public class P5 {
    public static int solution(int n, double k){
        if(n==0){
            return 0;
        }

        double values_in_previous_row = Math.pow(2, n-1);
        if(k<=values_in_previous_row){
            return solution(n-1, k);
        } else {
            return 1 - solution(n-1, k-values_in_previous_row);
        }
    }

    public static int kthGrammar(int n, int k) {
        return solution(n-1, k);
    }

    public static void main(String[] args) {
        int n = 2, k=2;
        
        System.out.println(kthGrammar(n, k));
    }
}
