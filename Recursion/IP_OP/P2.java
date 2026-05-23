package Recursion.IP_OP;

import java.util.*;

public class P2 {
    public static void compute_subset(String input, String output, int it, Set<String> res){
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

        Set<String> res_set = new HashSet<>();
        compute_subset(input, "", 0, res_set);
        List<String> res = new ArrayList<>();
        res.addAll(res_set);
        System.out.println(res);
    }
}
