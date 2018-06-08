import com.sun.java_cup.internal.runtime.Scanner;

import java.io.Serializable;
import java.util.Set;
import java.util.TreeSet;

public class Students implements Serializable {
    private Set<Student> Students;
    public Students(){
        Students = new TreeSet<Student>(new CompSurname());
    }
    public void add(Student St){
        Students.add(St);
    }
    public double averageMark(){
        double sum = 0;
        for(Student student: Students){
            sum+= student.getAverage();
        }
        return sum/Students.size();
    }
    public Student searchSurname(String surname){
        for(Student student: Students){
            if(student.getSurname.equalsIgnoreCase(surname)) return student;
        }
        return null;
    }
}
