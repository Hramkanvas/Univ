package seclab;

import java.util.InputMismatchException;

public class Run {
    public void run() {
        Input ip = new Input();
        System.out.println("Enter the quantity of rows: ");
        int rows = ip.inputInt();
        System.out.println("Enter the quantity of columns: ");
        int columns = ip.inputInt();
        try {
            Matrix matrix = new Matrix(rows, columns);
            try {
                int answer = ip.answer();
                try {
                    if (answer == 0) {
                        matrix.setMatrix();
                    } else {
                        matrix.setRandomMatrix();
                    }
                    matrix.showMatrix();
                    matrix.getMaxFromSortedRows();
                }catch (InputMismatchException e){
                    System.out.println("Wrong matrix input");
                }
            } catch (Exception e) {
                System.out.println("Symbols 'H' or 'R' only");
            }
        } catch (Exception e) {
            System.out.println("Wrong matrix order");
        }
    }
}
