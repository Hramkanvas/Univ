package mpackage;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class MFile {
    static public void writeDataToList(String path, List<List<String>> list) throws FileNotFoundException, IOException {
        try(Scanner scanner = new Scanner(new File(path)).useDelimiter("[;\r\n]+")){
            Scanner scan;
            List<String> item;
            while(scanner.hasNext()){
                scan = new Scanner(scanner.next()).useDelimiter("[ ]+");
                item = new ArrayList<>();
                while(scan.hasNext()){
                    item.add(scan.next());
                }
                list.add(item);
            }
        }
    }
}
