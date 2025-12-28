class Box{
    int length;
    int width;  
    int height;
    //default constructor
    Box(){
        length=1;
        width=1;
        height=1;
    }
    //parameterized constructor
    Box(int l, int w, int h){
        length=l;
        width=w;
        height=h;
    }
    //constructor for cube
    Box(int side){
        length=side;
        width=side;
        height=side;
    }
    //copy constructor 
    Box(Box b){
        length=b.length;
        width=b.width;
        height=b.height;
    }
    void display(){
        System.out.println("Length: " + length + ", Width: " + width + ", Height: " + height);
    }
}
class boxweight extends Box{
    double weight;
    boxweight(int l, int w, int h, double m){
        super(l,w,h);
        weight=m;
    }
    void displayweight(){
        System.out.println("Weight: " + weight);
    }
}
//this is multilevel inheritance boxprice->boxweight->Box, super automatically refers to immediate parent class
class boxprice extends boxweight{
    double price;
    boxprice(int l, int w, int h, double p){
        super(l,w,h,0);
        price=p;
    }
    void displayprice(){
        System.out.println("Price: " + price);
    }
}
public class inheritance{
    public static void main(String[] args) {
        Box b1=new Box();
        Box b2=new Box(2,3,4);
        Box b3=new Box(5);
        Box b4=new Box(b2); //using copy constructor
        //child reference to parent object is invalid because parent class does not know about child class
        // boxweight bw=new Box (2,3,4,5.5);
        Box b5=new boxweight(2,3,4,5.5); //parent reference to child object is valid    
        b1.display();
        b2.display();   
        b3.display();
        b4.display();
        b5.display();
        }
}