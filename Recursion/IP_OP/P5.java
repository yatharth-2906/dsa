package Recursion.IP_OP;

import java.util.ArrayList;
import java.util.List;

class P5{
    public static int findWinner(List<Integer> players, int n, int start, int k){
        if(n==1){
            return players.get(0);
        }

        int eliminated = (start+k-1+n)%n;
        players.remove(eliminated);
        return findWinner(players, n-1, eliminated, k);
    }

    public static int findTheWinner(int n, int k) {
        List<Integer> players = new ArrayList<>();

        for(int i=1; i<=n; i++){
            players.add(i);
        }

        return findWinner(players, n, 0, k);
    }

    public static void main(String[] args) {
        int n = 5, k = 2;

        System.out.println(findTheWinner(n, k));
    }
}