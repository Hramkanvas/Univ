package mpackage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.*;

public class MConsole {
    private List<List<String>> SortedBySumVyrList;
    private List<List<String>> Vyr;
    private List<List<String>> VyrStr;
    public MConsole() {
    }

    public void setVyrList(String inPath) throws IOException {
        Vyr = new ArrayList<>();
        MFile.writeDataToList(inPath, Vyr);
    }

    public void getSortedBySumVyrList(String outPath) throws FileNotFoundException {
        operatorListSortingBySum();
        writeListToFile(SortedBySumVyrList, outPath);
    }

    private void operatorListSortingBySum() {
        SortedBySumVyrList = new ArrayList<>(Vyr);
        SortedBySumVyrList.sort(new OperatorComparatorDown());
    }

    public void SecondProblem(String outPath2, String outPath3) throws FileNotFoundException {
        VyrStr = new ArrayList<>();
        List<String> newLine;
        for(List<String> line: Vyr){
            newLine = new ArrayList<>();
            for(String item: line){
                newLine.add(item);
            }
            VyrStr.add(newLine);
        }
        int i = 0;
        for (List<String> line : Vyr) {
            performAll(line, VyrStr.get(i));
            i++;
        }
        writeListToFile(VyrStr, outPath2);
        writeListToFile(Vyr, outPath3);
    }

    private void performAll(List<String> line, List<String> lineStr) {
        double result = 0;
        while (line.size() != 1) {
            switch (getCommandType(line)) {
                case 1:
                    makeMul(line, lineStr);
                    break;
                case 2:
                    makeDiv(line, lineStr);
                    break;
                case 3:
                    makeSum(line, lineStr);
                    break;
                case 4:
                    makeImp(line, lineStr);
                    break;
            }
        }
    }

    private void makeImp(List<String> line, List<String> lineStr) {
        int index = line.indexOf("-");
        double leftOperand = Double.parseDouble(line.get(index - 1));
        double rightOperand = Double.parseDouble(line.get(index + 1));
        line.remove(index + 1);
        line.remove(index);
        line.set(index - 1,((Double)(leftOperand - rightOperand)).toString());
        String leftStrOperand = lineStr.get(index - 1);
        String rightStrOperand = lineStr.get(index + 1);
        lineStr.remove(index + 1);
        lineStr.remove(index);
        lineStr.set(index - 1, "Sub(" + leftStrOperand + " , " + rightStrOperand + ")");
    }

    private void makeSum(List<String> line, List<String> lineStr) {
        int index = line.indexOf("+");
        double leftOperand = Double.parseDouble(line.get(index - 1));
        double rightOperand = Double.parseDouble(line.get(index + 1));
        line.remove(index + 1);
        line.remove(index);
        line.set(index - 1,((Double)(leftOperand + rightOperand)).toString());
        String leftStrOperand = lineStr.get(index - 1);
        String rightStrOperand = lineStr.get(index + 1);
        lineStr.remove(index + 1);
        lineStr.remove(index);
        lineStr.set(index - 1, "Add(" + leftStrOperand + " , " + rightStrOperand + ")");
    }

    private void makeDiv(List<String> line, List<String> lineStr) {
        int index = line.indexOf("/");
        double leftOperand = Double.parseDouble(line.get(index - 1));
        double rightOperand = Double.parseDouble(line.get(index + 1));
        line.remove(index + 1);
        line.remove(index);
        line.set(index - 1,((Double)(leftOperand / rightOperand)).toString());
        String leftStrOperand = lineStr.get(index - 1);
        String rightStrOperand = lineStr.get(index + 1);
        lineStr.remove(index + 1);
        lineStr.remove(index);
        lineStr.set(index - 1, "Div(" + leftStrOperand + " , " + rightStrOperand + ")");
    }

    private void makeMul(List<String> line, List<String> lineStr) {
        int index = line.indexOf("*");
        double leftOperand = Double.parseDouble(line.get(index - 1));
        double rightOperand = Double.parseDouble(line.get(index + 1));
        line.remove(index + 1);
        line.remove(index);
        line.set(index - 1,((Double)(leftOperand * rightOperand)).toString());
        String leftStrOperand = lineStr.get(index - 1);
        String rightStrOperand = lineStr.get(index + 1);
        lineStr.remove(index + 1);
        lineStr.remove(index);
        lineStr.set(index - 1, "Mul(" + leftStrOperand + " , " + rightStrOperand + ")");
    }

    private int getCommandType(List<String> line) {
        if(line.contains("*") || line.contains("/")){
            int indexM = line.indexOf("*");
            int indexD = line.indexOf("/");
            if(indexM == -1) return 2;
            else if(indexD == -1) return 1;
            else if(indexD > indexM) return 1;
            else return 2;
        }
        else {
            int indexS = line.indexOf("+");
            int indexI = line.indexOf("-");
            if(indexS == -1) return 4;
            else if(indexI == -1) return 3;
            else if(indexS > indexI) return 4;
            else return 3;
        }
    }

    private void writeListToFile(List<List<String>> list, String outPath) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(outPath)) {
            for (List<String> line : list) {
                for (String item : line) {
                    printStream.print(item + ' ');
                }
                printStream.println(';');
            }
        }
    }
}
