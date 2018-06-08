import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Student implements Serializable {
    private String name;
    private String surName;
    private String studentID;
    transient private double average;
    private List<Integer> grades;

    public Student(String name, String surName, String studentID, List<Integer> grades) {
        this.grades = new ArrayList<>(grades);
        this.name = name;
        this.studentID = studentID;
        this.surName = surName;
        writeAverage();
    }

    private void writeAverage() {
        double sum = 0;
        for (Integer mark : grades) {
            sum+=mark;
        }
        average = sum/grades.size();
    }


}
