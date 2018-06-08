package pack;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MClass {
    private  StringBuilder allText;
    private List<String> tokenList;
    MClass(String path) throws FileNotFoundException {
        allText = new StringBuilder();
        allTextFilling(path);
        tokenList = new ArrayList<>();
        tokenListFilling();
    }

    public List<String> getTokenList() {
        return tokenList;
    }

    private void allTextFilling(String path) throws FileNotFoundException {
        try(Scanner scanner = new Scanner(new File(path))){
            while (scanner.hasNextLine()){
                allText.append(scanner.nextLine()).append("\n");
            }
        }
    }
    private void tokenListFilling(){
        Scanner scanner = new Scanner(allText.toString()).useDelimiter("[{}]+");
        while (scanner.hasNext()){
            tokenList.add(scanner.next());
        }
    }
}
