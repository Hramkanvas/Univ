package kakoytopackage;

import java.io.*;
import java.util.*;

public class HtmlEditor implements Editor {
    private List<String> listOfRows;
    private List<String> listOfTags;
    private List<String> listOfRowsWithoutTags;
    private Map<String, Integer> mapOfContexts;

    public HtmlEditor() {
        listOfRows = new ArrayList<>();
        listOfRowsWithoutTags = new ArrayList<>();
        listOfTags = new ArrayList<>();
        mapOfContexts = new HashMap<>();
    }

    private void listsOfTagsAndWithoutThemFilling(StringBuilder sb) {
        int tagStart;
        int tagEnd;
        while (sb.indexOf("<") != -1) {
            tagStart = sb.indexOf("<");
            tagEnd = sb.indexOf(">") + 1;
            listOfTags.add(sb.substring(tagStart, tagEnd));
            sb.delete(tagStart, tagEnd);
        }
        while (sb.length() != 0) {
            listOfRowsWithoutTags.add(sb.substring(0, sb.indexOf("\n")));
            sb.delete(0, sb.indexOf("\n") + 1);
        }
    }

    public void getContext(String inPath, String outPath) throws IOException, FileNotFoundException {
        try (Scanner sc = new Scanner(new File(inPath)).useDelimiter("[;\n\r]+")) {
            int index;
            String context;
            boolean contains;
            while (sc.hasNext()) {
                index = 0;
                context = sc.next();
                contains = false;
                for (String item : listOfRowsWithoutTags) {
                    if (item.contains(context)) {
                        contains = true;
                        mapOfContexts.put(context, index);
                        break;
                    }
                    index++;
                }
                if (!contains) mapOfContexts.put(context, -1);
            }
        }
        MyPrint.writeContext(outPath, mapOfContexts);
    }

    public void getFallenContext(String path) throws IOException, FileNotFoundException {
        MyPrint.writeFallenContext(path, mapOfContexts);
    }

    public void sortTags() {
        listOfTags.sort(Comparator.comparingInt(String::length));
    }

    public void getSortedTags(String path) throws IOException, FileNotFoundException {
        MyPrint.writeSortedTags(path, listOfTags);
    }

    @Override
    public void read(String path) throws IOException, FileNotFoundException {
        StringBuilder sb = MyRead.readInSB(path);
        listsOfTagsAndWithoutThemFilling(sb);
    }
}
