package mpackage;

import java.util.Comparator;

public class OperatorLengthComparatorDown implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        Integer a1 = o1.substring(o1.indexOf('='), o1.length()).length();
        Integer a2 = o2.substring(o2.indexOf('='), o2.length()).length();
        return Integer.compare(a1, a2);
    }
}
