package lab;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.ParseException;
import java.util.InputMismatchException;


public class Run {
    public void run() {
        Input ip = new Input();
        String path = ip.setPath();
        Companies cmp = new Companies();
        try {
            cmp.listFilling(path);
            cmp.makeDecision(ip.variant());
        } catch (FileNotFoundException x) {
            cmp.logger.addLog(path + ": no such file or directory");
            System.out.println(path + ": no such file or directory");
        } catch (Exception x) {
            cmp.logger.addLog(x.toString());
            System.out.println(x.toString());
        } finally {
            try {
                cmp.logger.writeLogFile();
            } catch (IOException e) {
                System.out.println("logger error");
            }
        }
    }
}