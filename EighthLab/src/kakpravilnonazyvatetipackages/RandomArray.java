package kakpravilnonazyvatetipackages;
import java.util.InputMismatchException;
import java.util.Random;

public class RandomArray {
    public int[] array;
    public int dimension;
    private Input input;

    public RandomArray() throws InputMismatchException {
        input = new Input();
        dimension = input.getDimension();
        array = new int[dimension];
        arrayFilling();
    }

    private void arrayFilling() {
        Random random = new Random();
        for (int i = 0; i < dimension; i++) {
            array[i] = random.nextInt(dimension);
        }
    }

    public void showArray() {
        System.out.printf("\nDimension of your array = %d", dimension);
        System.out.println("\n***********");
        for (int item : array) {
            System.out.printf("\t%d\n", item);
        }
        System.out.print("***********");
    }

    public void arraySort() throws InputMismatchException {
        Thread thread = new Thread(new Sort(this, input.getSortType()));
        thread.start();
    }
}
