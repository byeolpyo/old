/* program that plays higher-lower with the player */

import java.util.Scanner;

public class hilo {
    public static void main(String[] args) {
        int num = (int)(1 + Math.random() *100);
        Scanner inp = new Scanner(System.in);
        
        System.out.println("guess a number in range [1, 100]");

        int counter = 0;
        boolean isDone = false;
        while(!isDone) {
            counter++;
            int guess = inp.nextInt();

            if(guess < num) {
                System.out.println("the number is higher than your guess");
            }
            else if(guess > num) {
                System.out.println("the number is lower than your guess");
            }
            else {
                System.out.println("your guess is right!\ntotal number of guesses: " + counter);
                isDone = true;
            }
        }
        inp.close();
    }
}
