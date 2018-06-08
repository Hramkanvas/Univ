package moypackage;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Matrix {
    List<List<Double>> matrix;

    public Matrix() {
        matrix = new ArrayList<List<Double>>();
    }

    public void readMatrixFromFile(String path) throws FileNotFoundException, InputMismatchException {
        try (Scanner scanner = new Scanner(new File("input.txt"))) {
            Scanner scanRow;
            ArrayList<Double> row;
            while (scanner.hasNextLine()) {
                row = new ArrayList<>();
                scanRow = new Scanner(scanner.nextLine()).useDelimiter("[ \r\n]+");
                while (scanRow.hasNext()) {
                    row.add(scanRow.nextDouble());
                }
                matrix.add(row);
            }
        }
        if(!isCorrect()){
            throw new InputMismatchException();
        }
    }
    public boolean isCorrect(){
        for (int i = 0; i < matrix.size()-1; i++){
            if(matrix.get(i).size()!=matrix.get(i+1).size()){
                return false;
            }
        }
        return true;
    }

    public void showMatrix() {
        for (List<Double> row : matrix) {
            for (Double item : row) {
                System.out.print(item + " ");
            }
            System.out.println();
        }
    }

    public void getSaddleElement() {
        int x;
        int y;
        boolean saddleExistence = false;
        for (int i = 0; i < matrix.size(); i++) {
            x = minInRow((ArrayList<Double>) matrix.get(i));
            y = i;
            if (isMaxInColumn(x, y)) {
                System.out.println("\nHere your saddle element: ");
                System.out.printf("With coordinates: (%d, %d)\n", x, y);
                saddleExistence = true;
                break;
            }
        }
        if (!saddleExistence) {
            System.out.println("There are no saddle elements in your matrix.");
        }
    }

    public int minInRow(ArrayList<Double> row) {
        int result = 0;
        double min = row.get(0);
        for (int i = 1; i < row.size(); i++) {
            if (min > row.get(i)) {
                min = row.get(i);
            }
        }
        return result;
    }

    public boolean isMaxInColumn(int x, int y) {
        double max = matrix.get(x).get(y);
        for (int i = 0; i < matrix.size(); i++) {
            if (i != x) {
                if (max < matrix.get(i).get(y)) {
                    return false;
                }
            }
        }
        return true;
    }

    public void sortWithComparator(String path) throws FileNotFoundException {
        for (int i = 0; i < matrix.size(); i++) {
            matrix.get(i).sort(new MyComparator());
        }
        writeMatrixInFile("output1.txt");
    }

    public void sortWithStream(String path) throws FileNotFoundException {
        List<Double> newList;
        for(int i = 0; i < matrix.size(); i++){
            matrix.set(i, ((ArrayList<Double>)matrix.get(i)).stream().sorted((o1, o2)->o2.compareTo(o1)).collect(Collectors.toList()));
        }
        writeMatrixInFile("output2.txt");
    }

    public void writeMatrixInFile(String path) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(path)) {
            for (List<Double> row : matrix) {
                for (Double item : row) {
                    printStream.print(item + " ");
                }
                printStream.println();
            }
        }
    }
}
