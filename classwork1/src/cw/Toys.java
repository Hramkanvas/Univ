package cw;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Toys {
    private List<Toy> toysList;
    private List<Toy> filteredLostOfToys;
    public Toys(){
        toysList = new ArrayList<>();
    }
    public void fillList(String path) throws IOException, FileNotFoundException, Exception{
        try(Scanner sc = new Scanner(new File(path)).useDelimiter("[;.\n\r]")){
            while(sc.hasNext()){
                toysList.add(new Toy(sc.next(), sc.nextInt(), sc.nextByte(), sc.nextByte()));
            }
        }
    }
    public void sortPrice(String outPath) throws  IOException{
        try(PrintStream ps = new PrintStream(outPath)){
            toysList.sort((a, b) -> a.getPrice() - b.getPrice());
        }
    }
    public List filter(int age){
        List<Toy> filteredToys = new ArrayList<>();
        for(Toy item: toysList){
            //отфильтровать, присвоить filteredLostToys
        }
        return //created list
    }

}
