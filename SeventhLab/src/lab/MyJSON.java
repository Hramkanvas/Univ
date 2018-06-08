package lab;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.List;

public class MyJSON implements CompanyWriter {
    @Override
    public void writeList(String path, List<Company> list) throws IOException, FileNotFoundException {
        StringBuilder sbJSON;
        int counter = 0;
        try (PrintStream psJSON = new PrintStream(path + ".json")) {
            psJSON.print("\n{\"companies\":[");
            for (Company item : list) {
                counter++;
                sbJSON = new StringBuilder()
                        .append("\n\t{")
                        .append("\n\t\t\"name\":\"")
                        .append(item.getName())
                        .append("\",")
                        .append("\n\t\t\"shortTitle\":\"")
                        .append(item.getShortTitle())
                        .append("\",")
                        .append("\n\t\t\"dateUpdate\":\"")
                        .append(item.getDateUpdate())
                        .append("\",")
                        .append("\n\t\t\"address\":\"")
                        .append(item.getAddress())
                        .append("\",")
                        .append("\n\t\t\"dateFoundation\":\"")
                        .append(item.getDateFoundation())
                        .append("\",")
                        .append("\n\t\t\"countEmployees\":")
                        .append(item.getCountEmployees())
                        .append(",")
                        .append("\n\t\t\"auditor\":\"")
                        .append(item.getAuditor())
                        .append("\",")
                        .append("\n\t\t\"phone\":\"")
                        .append(item.getPhone())
                        .append("\",")
                        .append("\n\t\t\"email\":\"")
                        .append(item.getEmail())
                        .append("\",")
                        .append("\n\t\t\"branch\":\"")
                        .append(item.getBranch())
                        .append("\",")
                        .append("\n\t\t\"activity\":\"")
                        .append(item.getActivity())
                        .append("\",")
                        .append("\n\t\t\"link\":\"")
                        .append(item.getLink())
                        .append("\"");
                if (counter == list.size()) {
                    sbJSON.append("\n\t}");
                } else {
                    sbJSON.append("\n\t},");
                }
                psJSON.print(sbJSON);
            }
            psJSON.print("\n]}");
        }
    }
}
