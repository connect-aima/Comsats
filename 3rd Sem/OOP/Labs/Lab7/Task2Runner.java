class Simple {

    public int num1;
    public int num2;

    Simple(int a, int b) {
        this.num1 = a;
        this.num2 = b;
    }

    void add() {
        int sum = num1 + num2;
        System.out.println("Sum is: " + sum);
    }

    void sub() {
        int sub = num1 - num2;
        System.out.println("Subtraction is: " + sub);
    }

    void mul() {
        int mul = num1 * num2;
        System.out.println("Multiplication is: " + mul);
    }

    void div() {
        int div = num1 / num2;
        System.out.println("Division is: " + div);
    }
}



class VerifiedSimple extends Simple {

    VerifiedSimple(int a, int b) {
        super(a, b);  
    }

    
    @Override
    void add() {
        if (num1 > 0 && num2 > 0)
            super.add();  
        else
            System.out.println("Error: Numbers must be greater than 0 for addition.");
    }

    
    @Override
    void sub() {
        if (num1 > 0 && num2 > 0 && num1>num2)
            super.sub();
        else
            System.out.println("Error: Numbers must be greater than 0 for subtraction and number 1 should be greater than number 2.");
    }

   
    @Override
    void mul() {
        if (num1 > 0 && num2 > 0)
            super.mul();
        else
            System.out.println("Error: Numbers must be greater than 0 for multiplication.");
    }

    
    @Override
    void div() {
        if (num1 > 0 && num2 > 0 )
            super.div();
        else
            System.out.println("Error: Numbers must be greater than 0 for division.");
    }
}



public class Task2Runner {
    public static void main(String[] args) {

       
        VerifiedSimple obj1 = new VerifiedSimple(10, 5);
        obj1.add();
        obj1.sub();
        obj1.mul();
        obj1.div();

        System.out.println("\n--- Testing with invalid inputs ---\n");

        
        VerifiedSimple obj2 = new VerifiedSimple(-3, 0);
        obj2.add();
        obj2.sub();
        obj2.mul();
        obj2.div();
    }
}
