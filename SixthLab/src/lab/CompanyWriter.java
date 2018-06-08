package lab;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

public interface CompanyWriter {
    void writeList(String path, List<Company> list) throws IOException, FileNotFoundException;
}
