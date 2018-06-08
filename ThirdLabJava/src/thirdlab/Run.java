package thirdlab;

import java.io.IOException;
import java.nio.file.NoSuchFileException;

public class Run {
    public void run(){
        Input ip = new Input();
        String path = ip.setPath();
        try {
            TextEditor ted = new TextEditor(path);
            ted.deleteWordsNumbers();
        } catch (NoSuchFileException x) {
            System.err.format("%s: no such file or directory", path);
        } catch (IOException x) {
            System.err.format("%s%n", x);
        }
    }
}
