package newpackage;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Matrix {
    private List<List<Double>> matrix;
    private int rowDimension;
    public Matrix(){
        matrix = new ArrayList<List<Double>>();
    }
    public void readMatrix() throws FileNotFoundException, InputMismatchException {
        String path = "input.txt";
        try(Scanner scanner = new Scanner(new File(path))){
            Scanner scanElements;
            List<Double> row;
            while(scanner.hasNextLine()) {
                scanElements = new Scanner(scanner.nextLine()).useDelimiter("[ \r\n]+");
                row = new ArrayList<>();
                while(scanElements.hasNext()){
                    row.add(scanElements.nextDouble());
                }
                matrix.add(row);
            }
        }
    }

    public void getSaddleElement() {
        int x;
        int y;

    }
    public boolean isMaxInRow(List<Double> row, int y){
        boolean result = false;
        for(double item:row){

        }
        return result;
    }

    public void sortMatrixStream() {
    }

    public void sortMatrixComparator() {
    }
}
