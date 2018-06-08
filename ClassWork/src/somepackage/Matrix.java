package somepackage;

import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class Matrix {
    private int[][] matrix;
    private int columns;
    private int rows;

    Matrix(int rows, int columns) throws Exception {
        if (columns < 1 || rows < 1) {
            throw new Exception("wrong matrix order");
        }
        this.rows = rows;
        this.columns = columns;
        matrix = new int[rows][columns];
    }

    public void setMatrix() {
        Scanner sc = new Scanner((System.in));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.printf("matrix[%d][%d] = ", i, j);
                matrix[i][j] = sc.nextInt();
            }
        }
    }

    public void setRandomMatrix() {
        Random rnd = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = rnd.nextInt(10);
            }
        }
    }

    public void showMatrix() {
        System.out.println();
        for (int[] row : matrix) {
            for (int item : row) {
                System.out.printf("   %d", item);
            }
            System.out.println();
        }
    }

    private Integer getFirstElement(Integer[] arr){
        return arr[0];
    }


    public void sortRow(){
        Integer[][] arr = new Integer[rows][columns];
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                arr[i][j] = matrix[i][j];
            }
        }
        Arrays.sort(arr, (a, b) -> getFirstElement(b) - getFirstElement(a));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                matrix[i][j] = arr[i][j];
            }
        }
    }
}
