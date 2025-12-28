// Upcasting is the process of assigning a child class object to a parent class reference. 
// It is safe and happens automatically because a child is always a type of its parent .Actually 
// only parents class(bcz reference is of parent) methods are accessible but if those methods are overridden in child class then
// that over ridden method in child class with get priority due to the concept of runtime polymorphism
// or dynamic dispatch. Downcasting is the process of converting a parent class reference back into a
// child class reference. Downcasting is risky and requires an explicit cast because not every parent
//object is a child object. Downcasting should only be done when the actual object is of the child
// type, otherwise it causes a runtime error called ClassCastException.

import java.util.Scanner;

class Animal {
    Scanner sc = new Scanner(System.in);
    void sound() {
        System.out.println("Animal makes a sound");
    }
}
class Dog extends Animal {
    void sound() {
        System.out.println("Dog barks");
    }
    void fetch() {
        System.out.println("Dog fetches the ball");
    }
}
public class upcastinganddownCasting {
    public static void main(String[] args) {
        // Upcasting: Child class object referenced by parent class reference
        Animal myAnimal = new Dog();
        //Refrence of parent class can only access methods of parent class even if object is of child class bcz refrence to child object just means if that method is overriden in child class then call that otherwise call parent class method
        myAnimal.sound(); // Outputs: Dog barks
        // myAnimal.fetch();  Error: Cannot find symbol bcz reference is of parent
        //  class which does not have fetch method to make it accessible we need to downcast it but if it 
        // only works if the object is of child class otherwise it will throw ClassCastException
        // Downcasting: Parent class reference cast back to child class reference
        if (myAnimal instanceof Dog) {
            Dog myDog = (Dog) myAnimal;
            myDog.fetch(); // Outputs: Dog fetches the ball
        }
    }
}
