package moypackage;

import java.util.Comparator;

public class MyComparator implements Comparator<Double> {

    @Override
    public int compare(Double o1, Double o2) {
        return Double.compare(o2, o1);
    }
}
