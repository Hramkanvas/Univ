package seclab;

import java.util.InputMismatchException;
import java.util.Objects;
import java.util.Scanner;

public class Input {
    private Scanner sc = new Scanner(System.in);

    public int inputInt() throws  InputMismatchException {
        int result = 0;
        result = sc.nextInt();
        return result;
    }

    public int answer() throws Exception{
        String answer;
        System.out.println("Would u like to create matrix with ur hands(Enter: 'H') or generate random(Enter: 'R')?");
        sc.nextLine();
        answer = sc.nextLine();
            if (Objects.equals(answer, "H")) {
                return 0;
            } else if (Objects.equals(answer, "R")) {
                return 1;
            } else throw new Exception();
    }
}