/* convert input age to seconds */

import java.util.Scanner;
public class sec {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("what is your age? ");
        long age = inp.nextLong();
        age *= 365.25*24*60*60;
        System.out.println("your age in seconds is " + age);
    }
}
