package lab;

import java.io.FileNotFoundException;
import java.io.IOException;

public class Run {
    public void run() {
        Input ip = new Input();
        String path = ip.setPath();
        try {
            TextEditor ted = new TextEditor(path);
            ted.write("my1.txt");
        } catch (FileNotFoundException x) {
            System.err.format("%s: no such file or directory", path);
        } catch (IOException x) {
            System.err.format("%s%n", x);
        }
    }
}