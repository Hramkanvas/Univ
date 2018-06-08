package kakoytopackage;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Collection;
import java.util.InputMismatchException;

public interface Editor {
    void read(String path) throws IOException, FileNotFoundException;
}
