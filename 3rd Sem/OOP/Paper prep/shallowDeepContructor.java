class Student {
    String name;
    int[] grades;
    Student(String name, int[] grades) {
        this.name = name;
        this.grades = grades;
    }
    // Shallow copy constructor
    //copied object is sharing the reference of array with original object , changes in one will reflect in other
    // Student(Student s) {
    //     this.name = s.name;
    //     this.grades = s.grades; // Shallow copy of the grades array
    // }
    //deep copy constructor
    //copied object has its own copy of array , changes in one will not reflect in other
   // Deep copy constructor
Student(Student s) {
    this.name = s.name;   // String is immutable → safe to copy reference

    this.grades = new int[s.grades.length]; // create new array
    for (int i = 0; i < s.grades.length; i++) {
        this.grades[i] = s.grades[i];       // copy values
    }
}

}
public class shallowDeepContructor {
    public static void main(String[] args) {
        Student Aima = new Student("Aima", new int[]{90, 80, 85});
        Student abdullah = new Student(Aima); // Using shallow copy constructor
        // Modifying the grades array in the original object
        Aima.grades[0] = 100;
        // Both original and shallowCopy reflect the change
        System.out.println("Aima grades: " + Aima.grades[0]); // Outputs 100
        System.out.println("Abdullah Copy grades: " + abdullah.grades[0]); // Outputs 100
    }
}
