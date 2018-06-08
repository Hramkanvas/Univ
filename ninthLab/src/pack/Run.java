package pack;

import java.io.FileNotFoundException;
import java.nio.file.FileSystemException;

public class Run {
    public void runProgram() {
        try{
                LineEditor lineEditor = new LineEditor();
                lineEditor.readLine();
                lineEditor.numbersRegex();
        }
        catch(FileNotFoundException e){
            System.out.println("File not found");
        }
        catch (FileSystemException e){
            System.out.println("Empty file");
        }
    }
}
