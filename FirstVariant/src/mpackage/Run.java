package mpackage;

import java.io.FileNotFoundException;

public class Run {
    public void runProgram() {
        try {
            MConsole mConsole = new MConsole();
            mConsole.setCommandList("input.txt");
            mConsole.getSortedCommandList("output1.txt");
            mConsole.performCommands("output2.txt", "logfile.txt");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
