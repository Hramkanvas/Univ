package fsdfsdf;

import java.io.*;

public class MyFile {
    public static FileInputStream openSourceFile(String inPath) throws IOException, FileNotFoundException {
        return new FileInputStream(inPath);
    }

    public static FileOutputStream openTargetFile(String outPath) throws IOException, FileNotFoundException {
        return new FileOutputStream(outPath);
    }

    public static void closeIn(FileInputStream fis) throws IOException {
        if (fis != null) {
            fis.close();
        }
    }

    public static void closeOut(FileOutputStream fos) throws IOException {
        if (fos != null) {
            fos.close();
        }
    }

    public static int availableBytesFile(FileInputStream fis) throws IOException {
        return fis != null ? fis.available() : -1;
    }

    public byte[] countBytesOfFile(FileInputStream fis) throws IOException {
        if (fis != null) {
            byte[] buffer = new byte[fis.available()];
            fis.read(buffer);
            return buffer;
        }
        return null;
    }

    public static byte[] readPart(FileInputStream fis, int carryingCapacity) throws IOException {
        int sizeBuffer;
        byte[] buffer;
        int available = fis.available();
        sizeBuffer = available > carryingCapacity ? carryingCapacity : available;
        buffer = new byte[available];
        return buffer;//nuzhno ne tak
    }
}
