package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Paths {
    private List<String> pathList;
    Paths(){
        pathList = new ArrayList<>();
    }

    public List<String> getPathList() {
        return pathList;
    }

    void listFilling(String input) throws FileNotFoundException {
        try(Scanner scanner = new Scanner(new File(input))){
            if(scanner.hasNextLine()){
                Scanner line = new Scanner(scanner.nextLine()).useDelimiter(";\r\n");
                while(line.hasNext()){
                    pathList.add(line.next());
                }
            }
        }
    }
}
