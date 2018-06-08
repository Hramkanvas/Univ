package kakpravilnonazyvatetipackages;

import java.util.Comparator;

public class upDigitsComparator implements Comparator<Integer> {

    @Override
    public int compare(Integer o1, Integer o2) {
        return Integer.compare(String.valueOf(o1).length(),String.valueOf(o2).length());
    }
}
