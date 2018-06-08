package pack;

import java.io.FileNotFoundException;
import java.io.PrintStream;

public class Write {
    public static void writeLine(LineEditor lineEditor, String path) throws FileNotFoundException {
        try(PrintStream printStream = new PrintStream(path)){
            printStream.print(lineEditor.getLine());
        }
    }
}
