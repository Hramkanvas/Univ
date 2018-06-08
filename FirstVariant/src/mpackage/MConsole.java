package mpackage;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

public class MConsole {
    private List<String> CommandList;
    private List<String> SortedCommandList;
    private String CurrentDirectory;
    private Map<String, List<String>> DIRList;
    private List<String> CDList;

    public MConsole() {
        CommandList = new ArrayList<>();
        CurrentDirectory = "C:\\";
    }

    public void setCommandList(String inPath) throws FileNotFoundException {
        try (Scanner scanner = new Scanner(new File(inPath)).useDelimiter("[;\n\r]+")) {
            while (scanner.hasNext()) {
                CommandList.add(scanner.next());
            }
        }
    }

    public void getSortedCommandList(String outPath) throws FileNotFoundException {
        commandListSorting();
        writeListToFile(SortedCommandList, outPath);
    }

    private void commandListSorting() {
        SortedCommandList = new ArrayList<>(CommandList);
        SortedCommandList.sort(new CommandComparatorDown());
    }

    private void writeListToFile(List<String> list, String outPath) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(outPath)) {
            Iterator iterator = list.iterator();
            while (iterator.hasNext()) {
                printStream.println(iterator.next());
            }
        }
    }

    public void performCommands(String outPathDIR, String outPathCD) throws FileNotFoundException {
        Iterator iterator = CommandList.iterator();
        String element;
        DIRList = new HashMap<>();
        CDList = new ArrayList<>();
        while (iterator.hasNext()) {
            element = (String) iterator.next();
            switch (typeOfCommand(element)) {
                case 0:
                    performCD(element);
                    break;
                case 1:
                    performCDP();
                    break;
                case 2:
                    performDIR();
                    break;
            }
        }
        writeMapToFile(DIRList, outPathDIR);
        writeListToFile(CDList, outPathCD);
    }

    private void writeMapToFile(Map<String, List<String>> dirList, String outPathDIR) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(outPathDIR)) {
            for (Map.Entry<String, List<String>> entry : DIRList.entrySet()) {
                printStream.println(entry.getKey());
                for (String item : entry.getValue()) {
                    printStream.println(item);
                }
            }
        }
    }

    private void performDIR() {
        List<String> namesList = new ArrayList<>();
        for (File item : (new File(CurrentDirectory)).listFiles()) {
            namesList.add(item.getName());
        }
        DIRList.put(CurrentDirectory, namesList);
    }

    private void performCDP() {
        int index = CurrentDirectory.lastIndexOf('\\');
        if (CurrentDirectory.indexOf('\\') != index) {
            CurrentDirectory = CurrentDirectory.substring(0, index);
            CDList.add("cd..");
            CDList.add("successful");
        } else {
            CDList.add("cd..");
            CDList.add("unsuccessful");
        }
    }

    private void performCD(String element) {
        CurrentDirectory = element.substring(1 + element.lastIndexOf(' ', element.indexOf(':')), element.length());
        CDList.add("cd " + CurrentDirectory);
        CDList.add("successful");
    }

    private int typeOfCommand(String element) {
        switch (element.charAt(2)) {
            case ' ':
                return 0;
            case '.':
                return 1;
            case 'r':
                return 2;
            default:
                return 3;
        }
    }
}
