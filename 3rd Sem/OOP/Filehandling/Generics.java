class Printer<T> {
    T value;

    Printer(T value) {
        this.value = value;
    }

    public void print(){
        System.out.println(value);
    }
}

public class Generics {
   public static void main(String[] args) {
    Printer<String> printer1=new Printer <> ("Aima");
    printer1.print();
    Printer<Integer> printer2=new Printer <> (23);
    printer2.print();
    Printer<Double> printer3=new Printer <> (23.0);
    printer3.print();
   }
    
}