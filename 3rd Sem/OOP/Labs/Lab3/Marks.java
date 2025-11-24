public class Marks {
    private int marks1;
    private int marks2;
    private int marks3;

    public Marks(int marks1, int marks2, int marks3) {
        setMarks1(marks1);
        setMarks2(marks2);
        setMarks3(marks3);
    }

    public void setMarks1(int marks) {
        if (marks < 0 || marks > 100) {
            System.out.println("Please enter valid marking");
        } else {
            marks1 = marks;
        }
    }
     public void setMarks2(int marks) {
       if (marks < 0 || marks > 100) {
            System.out.println("Please enter valid marking");
        } else {
            marks2 = marks;
        }
    }
     public void setMarks3(int marks) {
       if (marks < 0 || marks > 100) {
            System.out.println("Please enter valid marking");
        } else {
            marks3 = marks;
        }
    }
    public int getMark1(){
        return marks1;
    }
    public int getMark2(){
        return marks2;
    }
    public int getMark3(){
        return marks3;
    }

}