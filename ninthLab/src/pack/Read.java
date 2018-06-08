package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.FileSystemException;
import java.util.Scanner;

public class Read {
    public static void readLine(LineEditor lineEditor, String path) throws FileNotFoundException, FileSystemException {
        try(Scanner scanner = new Scanner(new File(path))){
            if(scanner.hasNextLine()){
                lineEditor.setLine(scanner.nextLine());
            }
            else{
                throw new FileSystemException("Empty file");
            }
        }
    }
}
