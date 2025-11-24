class Computer {
    protected int wordSize;       
    protected int memorySize;    
    protected int storageSize;   
    protected double speed;       

    
    public Computer() {
        wordSize = 64;
        memorySize = 8192;    
        storageSize = 512000; 
        speed = 3200;         
    }

   
    public Computer(int wordSize, int memorySize, int storageSize, double speed) {
        this.wordSize = wordSize;
        this.memorySize = memorySize;
        this.storageSize = storageSize;
        this.speed = speed;
    }

   
    public void display() {
        System.out.println("Word Size: " + wordSize + " bits");
        System.out.println("Memory Size: " + memorySize + " MB");
        System.out.println("Storage Size: " + storageSize + " MB");
        System.out.println("Speed: " + speed + " MHz");
    }
}



class Laptop extends Computer {
    private double length; 
    private double width; 
    private double height; 
    private double weight; 

   
    public Laptop() {
       
        length = 35.0;
        width = 24.0;
        height = 2.0;
        weight = 1.5;
    }

   
    public Laptop(int wordSize, int memorySize, int storageSize, double speed,
                  double length, double width, double height, double weight) {
       
        super(wordSize, memorySize, storageSize, speed);
        this.length = length;
        this.width = width;
        this.height = height;
        this.weight = weight;
    }

   
    public void display() {
        super.display(); 
        System.out.println("Length: " + length + " cm");
        System.out.println("Width: " + width + " cm");
        System.out.println("Height: " + height + " cm");
        System.out.println("Weight: " + weight + " kg");
    }
}





public class Task3Runner {
    public static void main(String[] args) {
        System.out.println("----- Default Laptop -----");
        Laptop defaultLaptop = new Laptop();
        defaultLaptop.display();

        System.out.println("\n----- Custom Laptop -----");
        Laptop customLaptop = new Laptop(64, 16384, 1000000, 4200,
                                         32.5, 22.0, 1.8, 1.2);
        customLaptop.display();
    }
}
