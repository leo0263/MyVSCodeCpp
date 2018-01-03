import java.util.HashMap;
import java.util.Scanner;
import java.io.File;

class iseng {
    static HashMap<String, Integer> data;
    public static void main(String args[]) throws Exception {
        data = new HashMap<>();
        data.put("satu", 1);
        data.put("dua", 2);
        data.put("tiga", 3);
        data.put("satu", 0);

        System.out.printf("satu : %d\n", data.get("satu"));
        System.out.printf("dua : %d\n", data.get("dua"));
        System.out.printf("tiga : %d\n", data.get("tiga"));
        System.out.printf("empat : %d\n", data.get("empat"));
    }
}