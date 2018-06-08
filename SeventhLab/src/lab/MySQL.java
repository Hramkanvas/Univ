package lab;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class MySQL {
    private Companies companies;

    public MySQL(Companies companies) {
        this.companies = companies;
    }

    public int getType(Scanner sc) {
        String element;
        int type = 0;
        boolean stop = false;
        while (!stop) {
            element = sc.next();
            if (element.equalsIgnoreCase("activity")) {
                return 1;
            } else if (element.equalsIgnoreCase("quantityOfEmployees")) {
                return 2;
            } else if (element.equalsIgnoreCase("shortTitle")) {
                return 3;
            }
        }
        return 0;
    }

    public void analyzeType(int type, Scanner scLine, int requestNumber) throws IOException {
        switch (type) {
            case 1:
                String activity = scLine.next();
                makeFirstType(activity, requestNumber);
                break;
            case 2:
                int downBorder;
                int upBorder;
                scLine.next();
                downBorder = scLine.nextInt();
                scLine.next();
                upBorder = scLine.nextInt();
                makeSecondType(downBorder, upBorder, requestNumber);
                break;
            case 3:
                String title = scLine.next();
                makeThirdType(title, requestNumber);
                break;
        }
    }

    public void makeRequest() throws IOException {
        int type = 0;
        int requestNumber = 0;
        try (Scanner sc = new Scanner(new File("requests.txt"))) {
            Scanner scLine;
            while (sc.hasNextLine()) {
                requestNumber++;
                scLine = new Scanner(sc.nextLine()).useDelimiter("[ \r\n=]+");
                analyzeType(getType(scLine), scLine, requestNumber);
            }
        }
    }

    public void makeFirstType(String activity, int numberOfRequest) throws IOException {
        companies.getCompaniesByActivity(activity, "request" + numberOfRequest);
    }

    public void makeSecondType(int downBorder, int upBorder, int numberOfRequest) throws IOException {
        companies.getCompaniesByQuantityOfEmployees(downBorder, upBorder, "request" + numberOfRequest);
    }

    public void makeThirdType(String shortTitle, int numberOfRequest) throws IOException {
        companies.getCompanyByShortTitle(shortTitle, "request" + numberOfRequest);
    }
}
