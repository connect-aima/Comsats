import java.util.ArrayList;
import java.util.List;

 class Student {
    final String name;
    final int age;
    final String[] courses = {"Mathematics", "Physics", "Chemistry"};

    // Constructor
    public Student() {
        this.name = "Aima";
        this.age = 20;
    }
    void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
       for (String course : courses) {
           System.out.println("Course: " + course);
       }
    }

    
}
public class StudentManagement {
    public static void main(String[] args) {
        Student student1 = new Student();
        Student student2 = new Student();
        student1.displayInfo();
        student2.displayInfo();
        
//         List<String> courses = new ArrayList<>();
//         courses.add("Mathematics");
//         courses.add("Physics");

//         Student student = new Student("Alice", 20, courses);

//         // Display student information
//         System.out.println("Name: " + student.getName());
//         System.out.println("Age: " + student.getAge());
//         System.out.println("Courses: " + student.getCourses());

//         // Add a new course
//         student.addCourse("Chemistry");
//         System.out.println("Updated Courses: " + student.getCourses());
//         List<String> coursesOfStd2=new ArrayList<>();
//         coursesOfStd2.add("Biology");
//         Student student2=new Student("Bob",22,coursesOfStd2);
//         System.out.println("Name: " + student2.getName());
//         System.out.println("Age: " + student2.getAge());
//         System.out.println("Courses: " + student2.getCourses());
//         student2.addCourse("History");
//         System.out.println("Updated Courses: " + student2.getCourses());
   }
}

