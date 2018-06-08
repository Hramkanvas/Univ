package kakpravilnonazyvatetipackages;

import java.util.Comparator;

public class downValueComparator implements Comparator<Integer> {

    @Override
    public int compare(Integer o1, Integer o2) {
        return Integer.compare(o2, o1);
    }
}
