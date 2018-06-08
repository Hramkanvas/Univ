package mpackagee;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.*;

public class MConsole {
    private List<String> OperatorList;
    private List<String> SortedByDigitsOperatorList;
    private List<String> SortedByLengthOperatorList;
    private List<String> CheckedOperatorList;

    public MConsole() {
        OperatorList = new ArrayList<>();
    }

    public void setOperatorList(String inPath) throws IOException {
        OperatorList = new ArrayList<>();
        MFile.writeDataToList(inPath, OperatorList);
    }

    public void getSortedByDigitsOperatorList(String outPath) throws FileNotFoundException {
        operatorListSortingByDigits();
        writeListToFile(SortedByDigitsOperatorList, outPath);
    }

    public void getSortedByLengthOperatorList(String outPath) throws FileNotFoundException {
        operatorListSortingByLength();
        writeListToFile(SortedByLengthOperatorList, outPath);
    }

    private void operatorListSortingByDigits() {
        SortedByDigitsOperatorList = new ArrayList<>(OperatorList);
        SortedByDigitsOperatorList.sort(new OperatorComparatorDown());
    }

    private void operatorListSortingByLength() {
        SortedByLengthOperatorList = new ArrayList<>(OperatorList);
        SortedByLengthOperatorList.sort(new OperatorLengthComparatorDown());
    }

    private int getType(String str) {
        Scanner scanner = new Scanner(str).useDelimiter("[ ]+");
        switch (scanner.next()) {
            case "char":
                return 1;
            case "String":
                return 2;
            case "double":
                return 3;
            case "int":
                return 4;
            case "long":
                return 5;
            case "byte":
                return 6;
            case "boolean":
                return 7;
            case "short":
                return 8;
            case "float":
                return 9;
        }
        return 10;
    }

    public void checkOperatorList(String outPath) throws FileNotFoundException {
        CheckedOperatorList = new ArrayList<>();
        for (String item : OperatorList) {
            switch (getType(item)) {
                case 1:
                    checkChar(item);
                    break;
                case 2:
                    checkString(item);
                    break;
                case 3:
                    checkDouble(item);
                    break;
                case 4:
                    checkInt(item);
                    break;
                case 5:
                    checkLong(item);
                    break;
                case 6:
                    checkByte(item);
                    break;
                case 7:
                    checkBool(item);
                    break;
                case 8:
                    checkShort(item);
                    break;
                case 9:
                    checkFloat(item);
                    break;
            }
        }
        writeListToFile(CheckedOperatorList, outPath);
    }

    private void checkFloat(String item) {
        String literal = getLiteral(item);
        try {
            Float.parseFloat(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private String getLiteral(String item) {
        return item.substring(item.indexOf('=') + 2, item.length() - 1);
    }

    private void checkShort(String item) {
        String literal = getLiteral(item);
        try {
            Short.parseShort(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkBool(String item) {
        String literal = getLiteral(item);
        try {
            Boolean.parseBoolean(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkByte(String item) {
        String literal = getLiteral(item);
        try {
            Byte.parseByte(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkLong(String item) {
        String literal = getLiteral(item);
        try {
            Long.parseLong(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkInt(String item) {
        String literal = getLiteral(item);
        try {
            Integer.parseInt(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkDouble(String item) {
        String literal = getLiteral(item);
        try {
            Double.parseDouble(literal);
            CheckedOperatorList.add(item + " - yes");
        } catch (Exception e) {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void checkString(String item) {
        String literal = getLiteral(item);
        if (literal.matches("^(\"[ -~]*\")$")) {
            CheckedOperatorList.add(item + " - yes");
        } else {
            CheckedOperatorList.add(item + " - no");
        }

    }

    private void checkChar(String item) {
        String literal = getLiteral(item);
        if (literal.matches("^('[ -~]')$")) {
            CheckedOperatorList.add(item + " - yes");
        } else {
            CheckedOperatorList.add(item + " - no");
        }
    }

    private void writeListToFile(List<String> list, String outPath) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(outPath)) {
            Iterator iterator = list.iterator();
            while (iterator.hasNext()) {
                printStream.println(iterator.next());
            }
        }
    }
}
