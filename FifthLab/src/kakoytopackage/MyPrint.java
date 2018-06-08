package kakoytopackage;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.List;
import java.util.Map;

public class MyPrint {

    public static void writeSortedTags(String path, List<String> list) throws FileNotFoundException {
        PrintStream ps = new PrintStream(path);
        for (String item : list) {
            ps.println(item);
        }
    }

    public static void writeFallenContext(String path, Map<String, Integer> mapOfContexts) throws FileNotFoundException {
        PrintStream ps = new PrintStream(path);
        for (Map.Entry<String, Integer> entry : mapOfContexts.entrySet()) {
            if (entry.getValue() == -1) {
                ps.printf("%s - %d", entry.getKey(), entry.getValue());
            }
        }
    }

    public static void writeContext(String path, Map<String, Integer> mapOfContexts) throws FileNotFoundException {
        PrintStream ps = new PrintStream(path);
        for (Map.Entry<String, Integer> entry : mapOfContexts.entrySet()) {
            ps.println(entry.getKey() + " - " + entry.getValue());
        }
    }
}
