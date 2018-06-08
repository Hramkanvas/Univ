package kakoytopackage;

import java.util.Scanner;

public class Input {
    public String setPath() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Please, enter the full name of your file: ");
        return sc.nextLine();
    }
}