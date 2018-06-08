package lab;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.List;

public class MyXML implements CompanyWriter {
    @Override
    public void writeList(String path, List<Company> list) throws IOException, FileNotFoundException {
        StringBuilder sbXML;
        try (PrintStream psXML = new PrintStream(path + ".xml")) {
            psXML.print("<companies>");
            for (Company item : list) {
                sbXML = new StringBuilder()
                        .append("\n<company>")
                        .append("\n\t<name>")
                        .append(item.getName())
                        .append("</name>")
                        .append("\n\t<shortTitle>")
                        .append(item.getShortTitle())
                        .append("</shortTitle>")
                        .append("\n\t<dateUpdate>")
                        .append(item.getDateUpdate())
                        .append("</dateUpdate>")
                        .append("\n\t<address>")
                        .append(item.getAddress())
                        .append("</address>")
                        .append("\n\t<dateFoundation>")
                        .append(item.getDateFoundation())
                        .append("</dateFoundation>")
                        .append("\n\t<countEmployees>")
                        .append(item.getCountEmployees())
                        .append("</countEmployees>")
                        .append("\n\t<auditor>")
                        .append(item.getAuditor())
                        .append("</auditor>")
                        .append("\n\t<phone>")
                        .append(item.getPhone())
                        .append("</phone>")
                        .append("\n\t<email>")
                        .append(item.getEmail())
                        .append("</email>")
                        .append("\n\t<branch>")
                        .append(item.getBranch())
                        .append("</branch>")
                        .append("\n\t<activity>")
                        .append(item.getActivity())
                        .append("</activity>")
                        .append("\n\t<link>")
                        .append(item.getLink())
                        .append("</link>")
                        .append("\n</company>");
                psXML.print(sbXML.toString());
            }
            psXML.print("\n</companies>");
        }
    }
}
