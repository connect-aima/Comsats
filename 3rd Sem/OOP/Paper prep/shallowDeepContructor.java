class Address{
    String city;
    Address(String c){
        city=c;
    }
    Address(Address other){
        city=other.city;
    }
    @Override
    
    public String toString() {
        return city;
    }

}
class Student{
    String name;
    Address add;
    Student(String n,Address add){
        name=n;
        this.add=add;
    }
    //shallow copy constructor
    // Student(Student other){
    //     name=other.name;
    //     add=other.add;
    // }
    //deep copy 
    Student(Student other){
        name=other.name;
        add=new Address(other.add);
    }

    //display
    void print(){
        System.out.println(name+" "+add);
    }
}


public class shallowDeepContructor {
   public static void main(String[] args) {
    Address add=new Address("isb");
    Student s1=new Student("Aima",add);
    Student s2=new Student(s1);
    s2.name="Abdullah";
    s2.add.city = "mandi";
    s1.print();
    s2.print();
   }
}
