package kakoytopackage;

import java.io.FileNotFoundException;
import java.io.IOException;


public class Run {
    public void run() {
        try {
            HtmlEditor html = new HtmlEditor();
            html.read("input1.html");
            html.getSortedTags("output1.txt");
            html.getContext("input2.txt", "output2.txt");
            html.getFallenContext("output3.txt");
        } catch (FileNotFoundException x) {
            System.err.format("%s: no such file or directory", "path");
        } catch (IOException x) {
            System.err.format("%s%n", x);
        }
    }

}