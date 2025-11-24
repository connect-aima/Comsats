interface Payable {
    double getPaymentAmount(); 
}
 class Invoice implements Payable {
    private String partNumber;
    private String partDescription;
    private int quantity;
    private double pricePerItem;

    public Invoice(String partNumber, String partDescription, int quantity, double pricePerItem) {
        this.partNumber = partNumber;
        this.partDescription = partDescription;
        this.quantity = quantity;
        this.pricePerItem = pricePerItem;
    }

    @Override
    public double getPaymentAmount() {
        return quantity * pricePerItem; 
    }

    @Override
    public String toString() {
        return "Invoice:\nPart Number: " + partNumber +
               "\nDescription: " + partDescription +
               "\nQuantity: " + quantity +
               "\nPrice per Item: " + pricePerItem;
    }
}

 abstract class Employee implements Payable {
    private String firstName;
    private String lastName;
    private String socialSecurityNumber;

    public Employee(String firstName, String lastName, String socialSecurityNumber) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.socialSecurityNumber = socialSecurityNumber;
    }

    @Override
    public String toString() {
        return "Employee: " + firstName + " " + lastName +
               "\nSSN: " + socialSecurityNumber;
    }
}

 class SalariedEmployee extends Employee {
    private double weeklySalary;

   
    public SalariedEmployee(String firstName, String lastName, String socialSecurityNumber, double weeklySalary) {
        super(firstName, lastName, socialSecurityNumber);
        this.weeklySalary = weeklySalary;
    }

    
    @Override
    public double getPaymentAmount() {
        return weeklySalary;
    }

    @Override
    public String toString() {
        return super.toString() + "\nWeekly Salary: " + weeklySalary;
    }
}

public class task2 {
     public static void main(String[] args) {
        
        Payable[] payables = new Payable[2];

        payables[0] = new Invoice("1234", "Laptop", 2, 55000.0);
        payables[1] = new SalariedEmployee("Aima", "Abbas", "123-45-6789", 35000.0);

        
        for (Payable currentPayable : payables) {
            System.out.println(currentPayable.toString());
            System.out.println("Payment Due: Rs " + currentPayable.getPaymentAmount());
            System.out.println("--------------------------------");
        }
    }
}
