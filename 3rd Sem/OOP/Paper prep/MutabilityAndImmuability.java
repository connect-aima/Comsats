import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public final class MutabilityAndImmuability {

    private final String accountNumber;
    private final String holderName;
    private final double balance;
    private final List<String> transactions;
    private final Date createdOn;

    public MutabilityAndImmuability(String accountNumber, String holderName, double balance, List<String> transactions, Date createdOn) {
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
        this.transactions = new ArrayList<>(transactions);     // made defensive copy
        this.createdOn = new Date(createdOn.getTime());             // made defendive copy
    }
    // ===== Accessors =====
    public String getAccountNumber() {
        return accountNumber;
    }

    public String getHolderName() {
        return holderName;
    }

    public double getBalance() {
        return balance;
    }

    public List<String> getTransactions() {
        return new ArrayList<>(transactions);   // returned defensive copy
    }

    public Date getCreatedOn() {
        return new Date(createdOn.getTime());      // returned defensive copy
    }
}
//mutable above i made it immutable 
// import java.util.ArrayList;
// import java.util.Date;
// import java.util.List;

// public class BankAccount {

//     private String accountNumber;
//     private String holderName;
//     private double balance;
//     private List<String> transactions;
//     private Date createdOn;

//     public BankAccount(String accountNumber, String holderName, double balance,
//                        List<String> transactions, Date createdOn) {
//         this.accountNumber = accountNumber;
//         this.holderName = holderName;
//         this.balance = balance;
//         this.transactions = transactions;     // shared reference
//         this.createdOn = createdOn;             // shared reference
//     }

//     // ===== Mutators =====
//     public void setHolderName(String holderName) {
//         this.holderName = holderName;
//     }

//     public void deposit(double amount) {
//         balance += amount;
//         transactions.add("Deposited: " + amount);
//     }

//     public void withdraw(double amount) {
//         balance -= amount;
//         transactions.add("Withdrawn: " + amount);
//     }

//     public void setCreatedOn(Date date) {
//         this.createdOn = date;
//     }

//     public void setTransactions(List<String> transactions) {
//         this.transactions = transactions;
//     }

//     // ===== Accessors =====
//     public String getAccountNumber() {
//         return accountNumber;
//     }

//     public String getHolderName() {
//         return holderName;
//     }

//     public double getBalance() {
//         return balance;
//     }

//     public List<String> getTransactions() {
//         return transactions;   // exposing internal state
//     }

//     public Date getCreatedOn() {
//         return createdOn;      // exposing internal state
//     }
// }
