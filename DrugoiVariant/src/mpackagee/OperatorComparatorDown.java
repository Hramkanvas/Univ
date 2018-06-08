package mpackagee;

import java.util.Comparator;

public class OperatorComparatorDown implements Comparator<String>{
    @Override
    public int compare(String o1, String o2) {
        Integer firstCount = 0;
        Integer secondCount = 0;
        for(int i = 0; i < o1.length(); i++){
            if(Character.isDigit(o1.charAt(i))){
                firstCount++;
            }
        }
        for(int i = 0; i < o2.length(); i++){
            if(Character.isDigit(o2.charAt(i))){
                secondCount++;
            }
        }
        return Integer.compare(firstCount, secondCount);
    }
}
