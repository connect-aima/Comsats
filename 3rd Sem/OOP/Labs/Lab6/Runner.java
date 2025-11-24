 class person {

    protected String name;
    protected String id;
    protected int phone;

    public person() {
        name = "NaginaNazar";
        id = "sp14bcs039";
        phone = 12345;
    }

    public person(String a, String b, int c) {
        name = a;
        id = b;
        phone = c;
    }

    public void setName(String a) {
        name = a;
    }

    public void setId(String j) {
        id = j;
    }

    public void setPhone(int a) {
        phone = a;
    }

    public String getName() {
        return name;
    }

    public String getid() {
        return id;
    }

    public int getPhone() {
        return phone;
    }

    public void display() {

        System.out.println("Name : " + name + "ID : " + id + "Phone : " +
                phone);
    }
}

 class student extends person {
    private String rollNo;
    private int marks;

    public student() {
        super();
        rollNo = "sp14bcs039";
        marks = 345;
    }

    public student(String a, String b, int c, String d, int e) {
        super(a, b, c);
        rollNo = d;
        marks = e;
    }

    public void setRollNo(String a) {
        rollNo = a;
    }

    public void setMarks(int a) {
        marks = a;
    }

    public String getRollNo() {
        return rollNo;
    }

    public int getMarks() {
        return marks;
    }

    public void display() {
        super.display();
        System.out.println("Roll # : " + rollNo + "\nMarks : " + marks);
    }
}

public class Runner {
    public static void main(String[] args) {
        student s = new student("Aima ", "s-09 ", 123, " sp24-bse-010 ", 50);
        s.display();
    }
}