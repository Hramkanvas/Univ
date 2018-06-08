package kakpravilnonazyvatetipackages;

import java.util.Arrays;
import java.util.InputMismatchException;

class Sort implements Runnable {
    private int type;
    private RandomArray randomArray;
    private Integer[] iArray;

    public Sort(RandomArray randomArray, int type) {
        this.type = type;
        this.randomArray = randomArray;
        parseArrayIntToInteger();
    }

    private void parseArrayIntToInteger() {
        iArray = new Integer[randomArray.dimension];
        for (int i = 0; i < randomArray.dimension; i++) {
            iArray[i] = randomArray.array[i];
        }
    }

    private void parseArrayIntegerToInt() {
        for (int i = 0; i < randomArray.dimension; i++) {
            randomArray.array[i] = iArray[i];
        }
    }

    private void upValueSort() {
        Arrays.sort(iArray);
    }

    private void downValueSort() {
        Arrays.sort(iArray, new downValueComparator());
    }

    private void upDigitsSort() {
        Arrays.sort(iArray, new upDigitsComparator());
    }

    private void downDigitsSort() {
        Arrays.sort(iArray, new downDigitsComparator());
    }

    @Override
    public void run() throws InputMismatchException {
        switch (type) {
            case 1:
                upValueSort();
                break;
            case 2:
                downValueSort();
                break;
            case 3:
                upDigitsSort();
                break;
            case 4:
                downDigitsSort();
                break;
        }
        parseArrayIntegerToInt();
        randomArray.showArray();
    }
}