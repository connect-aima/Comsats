import java.util.Date;

class Person {
    protected String name;
    protected long phone;
    protected String address;
    protected String email;

    Person(String name, long phone, String address, String email) {
        this.name = name;
        this.phone = phone;
        this.address = address;
        this.email = email;
    }

    public void display() {
        System.out.println("Name: " + name + 
                           " | Phone: " + phone + 
                           " | Address: " + address + 
                           " | Email: " + email);
    }
}

//  STUDENT CLASS 
class Student extends Person {
    private String status;

    Student(String name, long phone, String address, String email, String status) {
        super(name, phone, address, email);
        this.status = status;
    }

    public void display() {
        super.display();
        System.out.println(" Status: " + status);
    }
}

// EMPLOYEE CLASS 
class Employee extends Person {
    protected String office;
    protected double salary;
    protected Date dateHired;

    Employee(String name, long phone, String address, String email, String office, double salary, Date dateHired) {
        super(name, phone, address, email);
        this.office = office;
        this.salary = salary;
        this.dateHired = dateHired;
    }

    public void display() {
        super.display();
        System.out.println("Office: " + office + 
                           " | Salary: " + salary + 
                           " | Date Hired: " + dateHired);
    }
}

//  FACULTY CLASS 
class Faculty extends Employee {
    private String officeHours;
    private String rank;

    Faculty(String name, long phone, String address, String email, String office, double salary, Date dateHired,
            String officeHours, String rank) {
        super(name, phone, address, email, office, salary, dateHired);
        this.officeHours = officeHours;
        this.rank = rank;
    }

    public void display() {
        super.display();
        System.out.println("Office Hours: " + officeHours + 
                           " | Rank: " + rank);
    }
}

//  STAFF CLASS
class Staff extends Employee {
    private String title;

    Staff(String name, long phone, String address, String email, String office, double salary, Date dateHired, String title) {
        super(name, phone, address, email, office, salary, dateHired);
        this.title = title;
    }

    public void display() {
        super.display();
        System.out.println("Title: " + title);
    }
}

//  MAIN / RUNNER 
public class Task1Runner {
    public static void main(String[] args) {

        Date hireDate = new Date(); // 

        System.out.println("STUDENT ");
        Student s = new Student("Aima", 9234567890L, "Islamabad", "aima@email.com", "Freshman");
        s.display();

        System.out.println("\n EMPLOYEE ");
        Employee e = new Employee("Nagina", 92300111222L, "Karachi", "nagina@email.com", "Office #12", 60000, hireDate);
        e.display();

        System.out.println("\n FACULTY ");
        Faculty f = new Faculty("Ali", 92300999888L, "Lahore", "ali@email.com", "Office #5", 90000, hireDate, "9am-3pm", "Professor");
        f.display();

        System.out.println("\n STAFF ");
        Staff st = new Staff("Sara", 92300123456L, "Rawalpindi", "sara@email.com", "Admin Block", 40000, hireDate, "Manager");
        st.display();
    }
}
