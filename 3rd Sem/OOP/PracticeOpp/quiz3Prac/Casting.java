class Animal{
    public void identity(){
        System.out.println("i am animal");
    }
     public void Sound(){
        System.out.println("i am not  classified yet");
    }
}
class Dog extends Animal{
    public void Sound(){
        System.out.println("Woof Woof");
    }
}
public class Casting {
    public static void main(String[] args) {
        //upcasting -> actual type is dog and declared type is animal so all animal methods are accesable not dogs 
        Animal a =new Dog();
        a.Sound();//animal methods are accesable but if any method is overridden dog class then that will be used
        a.identity();
    }
}

//Down Casting 
class Parent {
    void show() {
        System.out.println("Parent show");
    }
}

class Child extends Parent {
    @Override
    void show() {
        System.out.println("Child show");
    }

    void childOnly() {
        System.out.println("Child-only method");
    }
}

public class Main {
    public static void main(String[] args) {

        Parent p = new Child();  // Upcasting
        p.show();                // Child show (overridden)

        Child c = (Child) p;     // Safe downcasting
        c.childOnly();           // now accessible

        Parent p2 = new Parent();   // pure parent object
        Child c2 = (Child) p2;      // ❌ runtime error
    }
}

