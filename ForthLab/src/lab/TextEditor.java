package lab;


import java.io.*;
import java.nio.file.*;
import java.util.Arrays;


public class TextEditor {
    private Path path;
    private String txt;
    private StringBuilder text;

    public String read(String fileName) throws IOException {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader in = new BufferedReader(new FileReader((new File(fileName).getAbsoluteFile())))) {
            String s;
            while ((s = in.readLine()) != null) {
                sb.append(s);
                sb.append("\n");
            }
        }
        return sb.toString();
    }

    public int startsWith(StringBuilder sb) {
        int a, b, c, cc, end, finish;
        a = sb.indexOf("//");
        b = sb.indexOf("/*");
        c = sb.indexOf("\'");
        cc = sb.indexOf("\"");
        end = sb.indexOf("\n");
        finish = sb.length();
        if (a == -1) a = finish + 1;
        if (b == -1) b = finish + 1;
        if (c == -1) c = finish + 1;
        if (cc == -1) cc = finish + 1;
        if (a < b && a < c && a < cc && a < end) return 1;
        else if (b < a && b < c && b < cc && b < end) return 2;
        else if (c < a && c < b && c < cc && c < end) return 3;
        else if (cc < a && cc < b && cc < c && cc < end) return 4;
        return 5;
    }

    /*public TextEditor(String fileName) throws FileNotFoundException, IOException {
        String ntxt = read(fileName);
        String regex = "((['\"])(?:(?!\\2|\\\\).|\\\\.)*\\2)|\\/\\/[^\\n]*|\\/\\*(?:[^*]|\\*(?!\\/))*\\*\\/";
        String substr = "$1";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(ntxt);
        txt = matcher.replaceAll(substr);
        System.out.println("\\\"\"");
    }*/
    public void eraseBeginning(StringBuilder sb, StringBuilder sbEdited, int type) {
        if (type == 1) {
            int index = sb.indexOf("//") + 2;
            sbEdited.append(sb.substring(0, index - 2));
            sb.delete(0, index);
        } else if (type == 2) {
            int index = sb.indexOf("/*") + 2;
            sbEdited.append(sb.substring(0, index - 2));
            sb.delete(0, index);
        } else if (type == 4) {
            int index = sb.indexOf("\"") + 1;
            sbEdited.append(sb.substring(0, index));
            sb.delete(0, index);
        } else if (type == 3) {
            int index = sb.indexOf("'") + 1;
            sbEdited.append(sb.substring(0, index));
            sb.delete(0, index);
        } else if (type == 5) {
            int index = sb.indexOf("\n") + 1;
            sbEdited.append(sb.substring(0, index));
            sb.delete(0, index);
        }
    }

    public void eraseDoubleSlashComment(StringBuilder sb, StringBuilder sbEdited) {
        int index = sb.indexOf("\n");
        sb.delete(0, index);
    }

    public void eraseMultiLineComment(StringBuilder sb) {
        int index = sb.indexOf("*/") + 2;
        sb.delete(0, index);
    }

    public void passThroughString(StringBuilder sb, StringBuilder sbEdited) {
        int number = 1;
        while (number % 2 != 0) {
            number = 0;
            int end = sb.indexOf("\"");
            while (end - 1 > -1 && sb.charAt(end - 1) == '\\') {
                end--;
                number++;
            }
            sbEdited.append(sb.substring(0, sb.indexOf("\"") + 1));
            sb.delete(0, sb.indexOf("\"") + 1);
        }
    }

    public void passThroughChar(StringBuilder sb, StringBuilder sbEdited) {
        sbEdited.append(sb.substring(0, sb.indexOf("'") + 1));
        sb.delete(0, sb.indexOf("'") + 1);
    }

    public TextEditor(String fileName) throws FileNotFoundException, IOException {
        StringBuilder sb = new StringBuilder(read(fileName));
        int type;
        text = new StringBuilder();
        while (sb.length() != 0) {
            type = startsWith(sb);
            eraseBeginning(sb, text, type);
            switch (type) {
                case 1:
                    eraseDoubleSlashComment(sb, text);
                    break;
                case 2:
                    eraseMultiLineComment(sb);
                    break;
                case 3:
                    passThroughChar(sb, text);
                    break;
                case 4:
                    passThroughString(sb, text);
                    break;
            }
        }
    }

    public void write(String fileName) throws IOException {
        try (PrintWriter out = new PrintWriter(new File(fileName).getAbsoluteFile())) {
            Arrays.stream(text.toString().split("\n")).filter(line -> line.length() != 0).forEach(out::println);
        }
    }
}