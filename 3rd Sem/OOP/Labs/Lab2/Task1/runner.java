// File: Runner.java
public class runner {
    public static void main(String[] args) {
        Circle cir1 = new Circle();          // default constructor is used so radius = 10
        System.out.println(cir1.calculateRadius());

        Circle cir2 = new Circle(3);         // customized constructor is used so radius = 3 which is passed
        System.out.println(cir2.calculateRadius());
    }
}
