package krkr;

import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Text {
    private List<String> str;
    private List<List<String>> text = new ArrayList<>();

    public void readText(String path) throws IOException {
        Scanner sc = new Scanner(new File(path));
        Scanner sc1;
        while (sc.hasNext()) {
            str = new ArrayList<>();
            sc1 = new Scanner(sc.nextLine()).useDelimiter("[#., ]");
            while (sc1.hasNext()) {
                str.add(sc1.next());
            }
            text.add(str);
        }
    }

    public void shifr(String outpath) throws FileNotFoundException, IOException {
        PrintStream ps = new PrintStream(outpath);
        StringBuilder sb;
        StringBuilder word;
        for (List<String> row : text) {
            sb = new StringBuilder();
            for (String item : row) {
                word = new StringBuilder();
                for (int i = 0, end = item.length(); i < end / 2; i++) {
                    if (end % 2 == 0) {
                        word.append(item.charAt(i)).append(item.charAt(end - i - 1));
                    } else {
                        if (i == end / 2 - 1) {
                            word.append(item.charAt(i)).append(item.charAt(end - i - 1)).append(item.charAt(i + 1));
                        } else {
                            word.append(item.charAt(i)).append(item.charAt(end - i - 1));
                        }
                    }
                }
                word.append("#");
                System.out.println(word);
                sb.append(word).append(" ");
            }
            ps.println(sb.toString());
        }
        ps.close();
    }

    public void deshifr(String inpath, String outpath) throws IOException {
        str.clear();
        text.clear();
        this.readText(inpath);
        PrintStream ps = new PrintStream(outpath);
        StringBuilder sb;
        StringBuilder word;
        for (List<String> row : text) {
            sb = new StringBuilder();
            for (String item : row) {
                word = new StringBuilder();
                for (int i = 0, end = item.length(); i < end; i += 2) {
                    word.append(item.charAt(i));
                }
                if (item.length() % 2 == 0) {
                    for (int i = item.length() - 1; i > 0; i -= 2) {
                        word.append(item.charAt(i));
                    }
                    sb.append(word).append(" ");
                } else {
                    for (int i = item.length() - 2; i > 0; i -= 2) {
                        word.append(item.charAt(i));
                    }
                    sb.append(word).append(" ");
                }
            }
            ps.println(sb);
        }
        ps.close();
    }
}
