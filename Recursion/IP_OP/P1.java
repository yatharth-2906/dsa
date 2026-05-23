package Recursion.IP_OP;

import java.util.*;

public class P1 {
    public static void compute_subset(String input, String output, int it, List<String> res){
        if(it == input.length()){
            res.add(output);
            return;
        }

        compute_subset(input, output, it+1, res);
        compute_subset(input, output+input.charAt(it), it+1, res);
        compute_subset(input, ""+input.charAt(it)+output, it+1, res);
    }

    public static void main(String[] args) {
        String input = "abcd";

        List<String> res = new ArrayList<>();
        compute_subset(input, "", 0, res);
        // Collections.sort(res);
        System.out.println(res);
    }
}
