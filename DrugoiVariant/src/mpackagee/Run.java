package mpackagee;

import java.io.IOException;

public class Run {
    public void runProgram() {
        try {
            MConsole mConsole = new MConsole();
            mConsole.setOperatorList("input.txt");
            mConsole.getSortedByDigitsOperatorList("output1.txt");
            mConsole.getSortedByLengthOperatorList("output2.txt");
            mConsole.checkOperatorList("output3.txt");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
