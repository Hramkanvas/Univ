package lab;

import java.io.IOException;
import java.io.PrintStream;

public class MLogger {
    private StringBuilder sb;
    public MLogger (){
       sb = new StringBuilder();
    }
    public void addLog(String string){
        sb.append(string).append("\n\n");
    }
    public void writeLogFile() throws IOException{
        try(PrintStream ps = new PrintStream("logfile.txt")) {
            ps.print(sb.toString());
        }
    }
}

