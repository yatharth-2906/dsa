package Recursion.IP_OP;

import java.util.*;

public class P4 {
    public static void generateBinaryNumbers(int ones, int zeroes, int n, String temp, Set<String> res){
        if(zeroes>ones || ones>n || zeroes>n){
            return;
        }

        if(ones+zeroes == n){
            if(temp.charAt(0) != '0' && zeroes<ones){
                res.add(temp);
            }
            return;
        }

        generateBinaryNumbers(ones+1, zeroes, n, temp+"1", res);
        generateBinaryNumbers(ones, zeroes+1, n, temp+"0", res);
        generateBinaryNumbers(ones+1, zeroes, n, ""+"1"+temp, res);
        generateBinaryNumbers(ones, zeroes+1, n, ""+"0"+temp, res);
    }

    public static void main(String[] args) {
        int n = 4;

        Set<String> res_set = new HashSet<>();
        generateBinaryNumbers(0, 0, n, "", res_set);
        List<String> res = new ArrayList<>();
        res.addAll(res_set);
        System.out.println(res);
    }
}
