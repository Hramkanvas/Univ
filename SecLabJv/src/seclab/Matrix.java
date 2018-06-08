package seclab;

import java.util.Arrays;
import java.util.InputMismatchException;
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

    public void setMatrix() throws InputMismatchException{
        Scanner sc = new Scanner((System.in));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                System.out.printf("matrix[%d][%d] = ", i, j);
                matrix[i][j] = sc.nextInt();
            }
        }
    }

    public void setRandomMatrix() {
        Random rd = new Random();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = rd.nextInt();
            }
        }
    }

    public void showMatrix() {
        System.out.println();
        for (int[] row : matrix) {
            for (int item : row) {
                System.out.printf("   %15d", item);
            }
            System.out.println();
        }
    }

    public void getMaxFromSortedRows() {
        int max = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (matrix[i][j] < max) {
                    max = matrix[i][j];
                }
            }
        }
        boolean sorted = false;
        boolean up = false;
        boolean down = false;
        for (int i = 0; i < rows; i++) {
            for (int k = 0; k < columns; k++) {
                if (matrix[i][k] > matrix[i][k + 1]) {
                    down = true;
                    for (int j = 1 + k; j < columns - 1; j++) {
                        if (matrix[i][j] < matrix[i][j + 1]) {
                            down = false;
                            break;
                        }
                    }
                    if (down) {
                        if (matrix[i][0] > max) {
                            max = matrix[i][0];
                        }
                        sorted = true;
                    }
                    break;
                } else if (matrix[i][k] < matrix[i][k + 1]) {
                    up = true;
                    for (int j = 1 + k; j < columns - 1; j++) {
                        if (matrix[i][j] > matrix[i][j + 1]) {
                            up = false;
                            break;
                        }
                    }
                    if (up) {
                        if (matrix[i][columns - 1] > max) {
                            max = matrix[i][columns - 1];
                        }
                        sorted = true;
                    }
                    break;
                }
            }
        }
        if (!sorted) {
            System.out.println("No one rows is sorted. ");
        } else {
            System.out.printf("max element = %d", max);
        }
    }
}