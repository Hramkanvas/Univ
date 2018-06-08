package kakpravilnonazyvatetipackages;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Input {
    private Scanner scanner;
    public Input(){
        scanner = new Scanner(System.in);
    }
    public int getDimension() throws InputMismatchException{
        System.out.println("Enter the dimension of your array: ");
        int result = scanner.nextInt();
        if(result < 1) {
            throw new InputMismatchException("dimension should be more than 0");
        }
        return result;
    }
    public int getSortType() throws InputMismatchException{
        System.out.println("\nEnter the sort type:\n 1 - increase by value\n 2 - decrease by value");
        System.out.println(" 3 - increase by the number of digits\n 4 - decrease by the number of digits");
        int result = scanner.nextInt();
        if( result < 1 || result > 4){
            throw new InputMismatchException("1, 2, 3 or 4 only");
        }
        return result;
    }
}