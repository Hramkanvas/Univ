package thirdlab;

import java.io.IOException;


import java.io.PrintStream;
import java.nio.charset.Charset;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class TextEditor {
    private Path path;
    private List<List<String>> text = new ArrayList<>();

    public TextEditor(String pathM)  throws NoSuchFileException, IOException {
        path = Paths.get(pathM);
        Path fp = path.toRealPath();
    }
    public void readTextFromFileToArrayList() throws IOException{
        List<String> line;
        try (Scanner sc = new Scanner(path)) {
            Scanner sc1;
            while (sc.hasNext()) {
                line = Arrays.stream(sc.nextLine().split("[ ]+"))
                        .filter(word -> !word.matches("^[0-9-.,]+$"))
                        .collect(Collectors.toList());
                text.add(line);
            }
        }
    }
    protected void deleteFile() throws IOException{
        if(Files.exists(path)){
            Files.delete(path);
        }
    }
    public void rewriteTextFile() throws  IOException{
        try(PrintStream ps = new PrintStream(path.toString())){
            StringBuilder sb;
            for(List<String> item: text){
                sb = new StringBuilder();
                for(String jtem: item){
                    if(!jtem.isEmpty()) {
                        sb.append(jtem).append(" ");
                    }
                }
                if(!sb.toString().isEmpty()) {
                    ps.println(sb.toString());
                }
            }
        }
    }
    public void deleteWordsNumbers() throws IOException{
        this.readTextFromFileToArrayList();
        this.deleteFile();
        this.rewriteTextFile();
    }
}
