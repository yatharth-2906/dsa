class P1{
    public static void print_numbers(int n){
        if(n == 0){
            return;
        }

        print_numbers(n-1);
        System.out.print(n + " ");
    }

    public static void main(String[] args) {
        int n = 10;

        print_numbers(n);
    }
}