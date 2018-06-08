package kakpravilnonazyvatetipackages;

import java.util.InputMismatchException;

public class Run {
    public void run(){
        try{
            RandomArray randomArray = new RandomArray();
            randomArray.showArray();
            randomArray.arraySort();
        }
        catch (InputMismatchException x){
            System.out.println(x);
            System.out.println("integers only");
        }
        catch (Exception x){
            System.err.println(x);
        }
    }
}
