package kakoytopackage;

import java.io.*;

public class MyRead {
    static StringBuilder readInSB(String path) throws IOException, FileNotFoundException {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader in = new BufferedReader(new FileReader((new File(path).getAbsoluteFile())))) {
            String s;
            while ((s = in.readLine()) != null) {
                sb.append(s);
                sb.append("\n");
            }
        }
        return sb;
    }
}
