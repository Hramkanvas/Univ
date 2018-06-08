package moypackage;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;

public class Run {
    public void runProgram() {
        try {
            Matrix matrix = new Matrix();
            matrix.readMatrixFromFile("input.txt");
            matrix.showMatrix();
            matrix.getSaddleElement();
            matrix.sortWithComparator("output1.txt");
            matrix.sortWithStream("output2.txt");
        }
        catch(InputMismatchException x){
            System.out.println("Something gone wrong while reading your matrix, please make sure it's correct");
        }
        catch (FileNotFoundException x){
            System.out.println("File not found.");
        }
    }
}
