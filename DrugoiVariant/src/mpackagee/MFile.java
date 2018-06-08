package mpackagee;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

public class MFile {
    static public void writeDataToList(String path, List<String> list) throws FileNotFoundException, IOException {
        try(Scanner scanner = new Scanner(new File(path)).useDelimiter("[;\r\n]+")){
            while(scanner.hasNext()){
                list.add(scanner.next()+';');
            }
        }
    }
}
