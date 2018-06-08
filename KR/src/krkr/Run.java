package krkr;

import java.io.IOException;

public class Run {
    public String path = "input.txt";
    public String path1 = "output1.txt";
    public String path2 = "output2.txt";
    public void run()  {
        try {
            Text text = new Text();
            text.readText(path);
            text.shifr(path1);
            text.deshifr(path1, path2);
        }
        catch (IOException e){
            System.out.println("Problems with your file");
        }
    }
}
