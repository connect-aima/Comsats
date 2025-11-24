import java.util.*;

interface Payable {
    double calculatePay();
}

interface Trainable {
    void attendTraining();
}

class Person{
    protected String name;
    protected int age;

    Person(String n , int a){
        this.name=n;
        this.age=a;
    }

    void introduce() {
        System.out.println("Hi, I'm " + name + ", age " + age);
    }

    
    final void sayHello() {
        System.out.println("Hello from Person class!");
    }
}

class Employee extends Person{
    protected int salary;

    Employee(String n , int a , int s){
        super(n, a);
        this.salary=s;
    }
     void work() {
        System.out.println(name + " is working in the company.");
    }

    
    @Override
    void introduce() {
        super.introduce(); 
        System.out.println("I am an Employee earning $" + salary);
    }
}

class Manager extends Employee implements Payable , Trainable{
    double bonus;

    Manager(String n , int a , int s, double b){
        super(n, a, s);
        this.bonus=b;
    }
    @Override
    void introduce(){
        super.introduce(); 
        System.out.println("I am an Manager earning $" );
    }
    @Override
    public double calculatePay(){
        return salary+bonus;
    }
    public void attendTraining(){
        System.out.println(name + "is attemding training" );
    }
}

class Student extends Person {
    private String course;
    private int regNo;

    Student(String name, int age, String course, int regNo) {
        super(name, age);
        this.course = course;
        this.regNo = regNo;
    }

    void study() {
        System.out.println(name + " is studying " + course);
    }

    @Override
    void introduce() {
        super.introduce();
        System.out.println("I am a Student with registration no. " + regNo);
    }
}

public class inheritence {
     public static void main(String[] args) {
       
        Manager m = new Manager("Aima", 25, 1200, 15000);
        System.out.println("\n--- Manager Info ---");
        m.introduce();
        m.work();
        m.attendTraining();
        System.out.println("Total Pay: $" + m.calculatePay());
        m.sayHello(); 

       
        Student s = new Student("Sara", 20, "Computer Science", 2025001);
        System.out.println("\n--- Student Info ---");
        s.introduce();
        s.study();
        s.sayHello(); 

      
        Employee e = new Employee("Ali", 30, 80000);
        System.out.println("\n--- Employee Info ---");
        e.introduce();
        e.work();
        e.sayHello();
    }
}
