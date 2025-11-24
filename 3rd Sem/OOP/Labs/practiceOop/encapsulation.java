import java.util.*;

class Customer {
    private String name;
    private String cnic;
    private String phoneNo;

    Customer(String n, String c, String p) {
        setName(n);
        setCnic(c);
        setPhn(p);
    }

    String getName() { return this.name; }
    String getCnic() { return this.cnic; }
    String getPhn() { return this.phoneNo; }

    public void setName(String n) {
        if (n != null) this.name = n;
        else System.out.println("Invalid Name");
    }

    public void setCnic(String cnic) {
        if (cnic != null && cnic.matches("\\d{13}"))
            this.cnic = cnic;
        else
            System.out.println(" Invalid CNIC: must be exactly 13 digits.");
    }

    public void setPhn(String phoneNumber) {
        if (phoneNumber != null && phoneNumber.matches("03\\d{9}"))
            this.phoneNo = phoneNumber;
        else
            System.out.println(" Invalid Phone Number: must start with 03 and be 11 digits long.");
    }
}


// ------------------ Aggregation + Composition --------------------
class Accounts {
    private String accountNumber;
    private int balance;
    private Customer owner; // Aggregation
    private TransactionsHistory history; // Composition

    Accounts(String aN, int b, Customer c) {
        setAccountNumber(aN);
        setBalance(b);
        setOwner(c);
        this.history = new TransactionsHistory(); // Composition: created inside
    }

    public void setAccountNumber(String accountNumber) {
        if (accountNumber.matches("\\d{10}"))
            this.accountNumber = accountNumber;
        else
            System.out.println("Invalid account number: must be 10 digits.");
    }

    public void setBalance(int b) {
        if (b < 0)
            System.out.println("Balance cannot be negative");
        else
            this.balance = b;
    }

    public void setOwner(Customer o) {
        if (o != null)
            this.owner = o;
        else
            System.out.println("Owner cannot be null ");
    }

    Customer getOwner() { return this.owner; }
    int getBalance() { return this.balance; }
    String getAccountNumber() { return this.accountNumber; }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println(" Deposit failed: amount must be positive.");
            return;
        }
        balance += amount;
        history.addTransaction("Deposit of " + amount); // composition usage
        System.out.println(" Deposit successful! New balance: " + balance);
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println(" Withdrawal failed: amount must be positive.");
            return;
        }
        if (balance < amount) {
            System.out.println(" Withdrawal failed: insufficient balance.");
            return;
        }
        balance -= amount;
        history.addTransaction("Withdrawal of " + amount); // composition usage
        System.out.println("Withdrawal successful! Remaining balance: " + balance);
    }

    public void showHistory() {
        history.displayHistory();
    }
}


// ------------------ Composition: Owned Helper Class --------------------
class TransactionsHistory {
    private ArrayList<String> records = new ArrayList<>();

    public void addTransaction(String record) {
        records.add(record);
    }

    public void displayHistory() {
        System.out.println("\nTransaction History:");
        for (String r : records) {
            System.out.println("- " + r);
        }
    }
}


// ------------------ Aggregation Usage --------------------
class Transactions {
    private String transactionId;
    private double amount;
    private String type;
    private Accounts account;

    Transactions(String transactionId, double amount, String type, Accounts account) {
        if (transactionId == null || transactionId.isEmpty()) {
            System.out.println(" Invalid transaction ID");
            return;
        }
        if (amount <= 0) {
            System.out.println(" Invalid amount!");
            return;
        }
        if (!type.equalsIgnoreCase("DEPOSIT") && !type.equalsIgnoreCase("WITHDRAW")) {
            System.out.println(" Invalid transaction type!");
            return;
        }
        if (account == null) {
            System.out.println(" Account cannot be null!");
            return;
        }

        this.transactionId = transactionId;
        this.amount = amount;
        this.type = type.toUpperCase();
        this.account = account;
    }

    public void processTransaction() {
        if (type.equals("DEPOSIT"))
            account.deposit(amount);
        else if (type.equals("WITHDRAW"))
            account.withdraw(amount);
    }
}


// ------------------ MAIN --------------------
public class encapsulation {
    public static void main(String[] args) {
        // Step 1: Create a Customer (independent object)
        Customer c1 = new Customer("Aima", "1234567890123", "03451234567");

        // Step 2: Create an Account (Aggregation)
        Accounts acc1 = new Accounts("1234567890", 10000, c1);

        // Step 3: Perform some transactions (Aggregation)
        Transactions t1 = new Transactions("T001", 5000, "DEPOSIT", acc1);
        t1.processTransaction();

        Transactions t2 = new Transactions("T002", 3000, "WITHDRAW", acc1);
        t2.processTransaction();

        // Step 4: View composed transaction history
        acc1.showHistory();
    }
}
