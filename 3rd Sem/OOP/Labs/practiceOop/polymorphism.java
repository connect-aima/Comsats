abstract class Animal {
    String name;

    Animal(String name) {
        this.name = name;
    }

    abstract void intro();
}

class Birds extends Animal {
    Birds(String name) {
        super(name);
    }
    

    void intro() {
        System.out.println("I am " + name);
    }
}

class Mammals extends Animal {
    Mammals(String name) {
        super(name);
    }

    void intro() {
        System.out.println("I am " + name);
    }
}

public class polymorphism {
    public static void main(String[] args) {
        Mammals m1 = new Mammals("Elephant");
        m1.intro();
    }
}
