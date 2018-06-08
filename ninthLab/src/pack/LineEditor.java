package pack;

import java.io.FileNotFoundException;
import java.nio.file.FileSystemException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LineEditor {
    private String line;
    public void setLine(String line){
        this.line = line;
    }
    public String getLine(){
        return line;
    }
    public void readLine() throws FileNotFoundException, FileSystemException {
        Read.readLine(this, "input.txt");
    }
    public void bracketsRegex(){
        line = line.replaceAll("\\([^)]*\\)+","");
        System.out.println(line);
    }
    public void numbersRegex() throws FileNotFoundException {
        line = line.replaceAll("([0-9]{2})([0-9]+)","$1");
        Write.writeLine(this, "output.txt");
    }
    public void  insignificantZerosRegex() throws FileNotFoundException {
        line = line.replaceAll("( 0+)"," ");
        Write.writeLine(this, "output.txt");
    }
}
