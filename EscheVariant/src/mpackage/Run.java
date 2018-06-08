package mpackage;

import java.io.IOException;

public class Run {
    public void runProgram() {
        try {
            MConsole mConsole = new MConsole();
            mConsole.setVyrList("input.txt");
            mConsole.getSortedBySumVyrList("output1.txt");
            mConsole.SecondProblem("output2.txt", "output3.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
