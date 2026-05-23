package Recursion.IP_OP;

import java.util.*;

public class P3 {
    public static void generateParanthesis(int open, int closed, int n, String temp, List<String> res){
        if(closed>open || open>n || closed>n){
            return;
        }

        if(open+closed==2*n){
            res.add(temp);
            return;
        }

        generateParanthesis(open+1, closed, n, temp+"(", res);
        generateParanthesis(open, closed+1, n, temp+")", res);
    }

    public static void main(String[] args) {
        int n = 3;

        List<String> res = new ArrayList<>();
        generateParanthesis(1, 0, n, "(", res);
        System.out.println(res);
    }
}
