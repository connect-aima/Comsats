class Printer<T> {
    T value;

    Printer(T value) {
        this.value = value;
    }

    public void print(){
        System.out.println(value);
    }
}
class Surprise<T>{
    T gift;
    Surprise(T gift){
        this.gift=gift;
    }
    T getGift(){
        return gift;
    }
}

public class Generics {
   public static void main(String[] args) {
    // Printer<String> printer1=new Printer <> ("Aima");
    // printer1.print();
    // Printer<Integer> printer2=new Printer <> (23);
    // printer2.print();
    // Printer<Double> printer3=new Printer <> (23.0);
    // printer3.print();
    Surprise<Integer> s1=new Surprise<>(21);
    Surprise<String> s2=new Surprise<>("Aima");
    Integer gift1=s1.getGift();
    System.out.println(gift1);
    String gift2=s2.getGift();
    System.out.println(gift2);
   }
    
}