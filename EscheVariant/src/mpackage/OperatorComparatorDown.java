package mpackage;

import java.util.Comparator;
import java.util.List;

public class OperatorComparatorDown implements Comparator<List<String>> {
    @Override
    public int compare(List<String> o1, List<String> o2) {
        Integer a1 = 0;
        Integer a2 = 0;
        for (String item : o1) {
            try {
                a1 += Integer.parseInt(item);
            } catch (Exception e) {

            }
        }
        for (String item : o2) {
            try {
                a2 += Integer.parseInt(item);
            } catch (Exception e) {

            }
        }
        return Integer.compare(a1, a2);
    }
}
