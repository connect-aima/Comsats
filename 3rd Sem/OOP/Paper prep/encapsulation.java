class Student{
    private String name;
    private int age;
    Student(String name,int age){
        setName(name);
        setAge(age);
    }
    //mutators
    void setName (String name){
         this.name=name;
    }
    void setAge(int age){
        if(age>=0){
             this.age=age;
        }else{
            this.age=0;
        }
    }
    //accessors
    String getName (){
        return this.name;
    }
    int getAge(){
        return this.age;
    }
}

public class encapsulation {
    public static void main(String[] args) {
        Student s1=new Student("Aima", 21);
        s1.setName("Syeda Aima Abbas");
        System.out.println(s1.getName());
        System.out.println(s1.getAge());
    }
}
