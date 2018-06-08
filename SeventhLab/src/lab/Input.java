package lab;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Input {
    private Scanner sc = new Scanner(System.in);
    public String setPath() {
        System.out.println("Please, enter the full name of your file: ");
        return sc.nextLine();
    }
    public int variant() throws InputMismatchException{
        System.out.println("1 - getCompanyByShortTitle\n2 - getCompaniesByActivity\n3 - getCompaniesByIndustry\n4 - getCompaniesByDateOfFoundation\n5 - getCompaniesByQuantityOfEmployees");
        return sc.nextInt();
    }
    public String getTitle(){
        System.out.println("Enter the title: ");
        return sc.next();
    }

    public String getActivity(){
        System.out.println("Enter the activity: ");
        return sc.next();
    }

    public String getIndustry(){
        System.out.println("Enter the industry: ");
        return sc.next();
    }

    public String getDateDown(){
        System.out.println("Enter the date(down border): ");
        String result = sc.next();
        return result;
    }
    public String getDateUp() throws  InputMismatchException{
        System.out.println("Enter the date(up border): ");
        String result = sc.next();
        return result;
    }

    public int getEmployeesDown() throws InputMismatchException{
        System.out.println("Enter the down border of the employees quantity: ");
        int result = sc.nextInt();
        if(result < 0) throw new InputMismatchException("wrong quantity of employees format");
        return result;
    }
    public int getEmployeesUp() throws  InputMismatchException{
        System.out.println("Enter the up border of the employees quantity: ");
        int result = sc.nextInt();
        if(result < 0) throw new InputMismatchException("wrong quantity of employees format");
        return result;
    }
}