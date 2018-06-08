package lab;


import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

import java.util.stream.Collectors;

public class Companies implements Decision {
    private List<Company> companies;
    private List<Company> companiesShortTitle;
    private List<Company> companiesInTheSameBranch;
    private List<Company> companiesWithTheSameActivity;
    private List<Company> companiesDateOfFoundationInterval;
    private List<Company> companiesCountOfEmployeesInterval;
    public String mPath;
    private MyXML xml;
    private MyJSON json;
    public MLogger logger;

    public Companies() {
        companies = new ArrayList<>();
        logger = new MLogger();
        logger.addLog("Starting our program...");
        logger.addLog(Calendar.getInstance().toString());
        json = new MyJSON();
        xml = new MyXML();
    }

    void listFilling(String path) throws IOException, FileNotFoundException, ParseException {
        mPath = path;
        try (Scanner sc = new Scanner(new File(path)).useDelimiter("[,\n\r]+")) {
            while (sc.hasNext()) {
                companies.add(new Company(sc.next(), sc.next(), sc.next(), sc.next(), sc.next(), sc.nextInt(),
                        sc.next(), sc.next(), sc.next(), sc.next(), sc.next(), sc.next()));
            }
        }
        logger.addLog("ListFilling finished successfully");
    }

    public void getCompanyByShortTitle(String shortTitle, String path) throws IOException, FileNotFoundException {
        companiesShortTitle = (List<Company>) companies.stream()
                .filter(toy -> toy.getShortTitle().equalsIgnoreCase(shortTitle))
                .collect(Collectors.toList());
        xml.writeList(path, companiesShortTitle);
        json.writeList(path, companiesShortTitle);
        logger.addLog("getCompanyByShortTitle finished successfully");
    }

    public void getCompaniesByIndustry(String branch, String path) throws IOException, FileNotFoundException {
        companiesInTheSameBranch = (List<Company>) companies.stream()
                .filter(toy -> toy.getBranch().equalsIgnoreCase(branch))
                .collect(Collectors.toList());
        xml.writeList(path, companiesInTheSameBranch);
        json.writeList(path, companiesInTheSameBranch);
        logger.addLog("getCompaniesByIndustry finished successfully");

    }

    public void getCompaniesByActivity(String activity, String path) throws IOException, FileNotFoundException {
        companiesWithTheSameActivity = (List<Company>) companies.stream()
                .filter(toy -> toy.getActivity().equalsIgnoreCase(activity))
                .collect(Collectors.toList());
        xml.writeList(path, companiesWithTheSameActivity);
        json.writeList(path, companiesWithTheSameActivity);
        logger.addLog("getCompaniesByActivity finished successfully");
    }

    public void getCompaniesByDateOfFoundation(String downDate, String upDate, String path) throws IOException, FileNotFoundException, ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("d/m/yyyy");
        Date dDate = sdf.parse(downDate);
        Date uDate = sdf.parse(upDate);
        companiesDateOfFoundationInterval = (List<Company>) companies.stream()
                .filter(toy -> toy.getDateFoundation().after(dDate) && toy.getDateFoundation().before(uDate))
                .collect(Collectors.toList());
        xml.writeList(path, companiesDateOfFoundationInterval);
        json.writeList(path, companiesDateOfFoundationInterval);
        logger.addLog("getCompaniesByDateOfFoundation finished successfully");
    }

    public void getCompaniesByQuantityOfEmployees(int downQ, int upQ, String path) throws IOException, FileNotFoundException {
        companiesCountOfEmployeesInterval = (List<Company>) companies.stream()
                .filter(toy -> toy.getCountEmployees() > downQ && toy.getCountEmployees() < upQ)
                .collect(Collectors.toList());
        xml.writeList(path, companiesCountOfEmployeesInterval);
        json.writeList(path, companiesCountOfEmployeesInterval);
        logger.addLog("getCompaniesByQuantityOfEmployees finished successfully");
    }

    public void makeDecision(int variant) throws IOException, ParseException {
        Input in = new Input();
        switch (variant) {
            case 1:
                getCompanyByShortTitle(in.getTitle(), "my1");
                break;
            case 2:
                getCompaniesByActivity(in.getActivity(), "my2");
                break;
            case 3:
                getCompaniesByIndustry(in.getIndustry(), "my3");
                break;
            case 4:
                getCompaniesByDateOfFoundation(in.getDateDown(), in.getDateUp(), "my4");
                break;
            case 5:
                getCompaniesByQuantityOfEmployees(in.getEmployeesDown(), in.getEmployeesUp(), "my5");
                break;
        }
    }

}
