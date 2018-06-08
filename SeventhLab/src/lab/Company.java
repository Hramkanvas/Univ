package lab;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class Company {
    private String name;
    private String shortTitle;
    private String dateUpdate;
    private String address;

    private Date dateFoundation;
    private int countEmployees;
    private String auditor;
    private String phone;
    private String email;
    private String branch;
    private String activity;
    private String link;

    public Company(String name, String shortTitle, String dateUpdate, String address, String dateFoundation
            , int countEmployees, String auditor, String phone, String email, String branch, String activity, String link) throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("d/m/yyyy");
        this.name = name;
        this.shortTitle = shortTitle;
        this.dateUpdate = dateUpdate;
        this.address = address;
        this.dateFoundation = sdf.parse(dateFoundation);
        this.countEmployees =  countEmployees;
        this.auditor = auditor;
        this.phone =  phone;
        this.email = email;
        this.branch = branch;
        this.activity = activity;
        this.link = link;
    }

    public Company()throws ParseException {
        this("", "", "", "", "0/0/0", 0, "", "", "", "", "", "");
    }

    public String getName() {
        return this.name;
    }

    public String getShortTitle() {
        return this.shortTitle;
    }

    public String getDateUpdate() {
        return this.dateUpdate;
    }

    public String getAddress() {
        return this.address;
    }

    public Date getDateFoundation() {
        return this.dateFoundation;
    }

    public String getAuditor() {
        return this.auditor;
    }

    public String getEmail() {
        return this.email;
    }

    public String getBranch() {
        return this.branch;
    }

    public String getActivity() {
        return this.activity;
    }

    public String getLink() {
        return this.link;
    }

    public int getCountEmployees() {
        return this.countEmployees;
    }

    public String getPhone() {
        return this.phone;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(name).append(';')
                .append(shortTitle).append(';')
                .append(dateUpdate).append(';')
                .append(address).append(';')
                .append(dateFoundation).append(';')
                .append(countEmployees).append(';')
                .append(auditor).append(';')
                .append(phone).append(';')
                .append(email).append(';')
                .append(branch).append(';')
                .append(activity).append(';')
                .append(link).append(';');
        return sb.toString();
    }
}
