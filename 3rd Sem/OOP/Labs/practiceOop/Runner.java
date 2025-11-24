//array of objects and passing arrays of objects in another class

import java.util.Scanner;

//array of object
 class Student {
    // atrributes
    String name;
    int reg;
    int marks;

    // arguement constructor
    Student() {
        this.name = null;
        this.reg = 0;
    }

    // arguement constructor
    Student(String n, int r){
        this.name=n;
        this.reg=r;
    }

    void show() {
        System.out.println(name + " has registration number " + reg);

    }
    
}
// class that has method to take array as input
class Report {
    static double calculateAverage(Student[] students) {
        int total = 0;
        for (Student s : students) total += s.marks;
        return total / (double) students.length;
    }
}

public class Runner {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Student[] students = new Student[3];
        for (int i = 0; i < 3; i++) {
            students[i] = new Student();
            System.out.print("Enter name of Student " +(i+1) + ": ");
           students[i].name = input.next();
            System.out.print("Enter reg of Student " + (i+1) + ": ");
            students[i].reg = input.nextInt();
            System.out.print("Enter marks of Student " +(i+1) + ": ");
           students[i].marks = input.nextInt();
        }
        for (int i = 0; i < students.length; i++) {
            students[i].show();
        }
        System.out.println("Average Marks: " + Report.calculateAverage(students));
        input.close();
    }
}

//using arrayList
// import java.util.*;

// class Customer {
//     String name;
//     Customer(String name) { this.name = name; }
// }

// public class Shop {
//     public static void main(String[] args) {
//         List<Customer> customers = new ArrayList<>();
//         customers.add(new Customer("Ayesha"));
//         customers.add(new Customer("Bilal"));
//         customers.add(new Customer("Hina"));

//         for (Customer c : customers)
//             System.out.println(c.name);
//     }
// }

