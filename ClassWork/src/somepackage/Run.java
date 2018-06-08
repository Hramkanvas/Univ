package somepackage;

public class Run {
    public void run() {
        Input ip = new Input();

        System.out.println("Enter the quantity of rows: ");
        int rows = ip.inputInt();
        System.out.println("Enter the quantity of columns: ");
        int columns = ip.inputInt();
        try {
            Matrix matrix = new Matrix(rows, columns);
            int answer = ip.answer();
            if (answer == 0) {
                matrix.setMatrix();
            } else {
                matrix.setRandomMatrix();
            }
            matrix.showMatrix();
            matrix.sortRow();
            matrix.showMatrix();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}