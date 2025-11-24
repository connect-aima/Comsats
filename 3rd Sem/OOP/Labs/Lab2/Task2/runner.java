import Task2.Account;

public class runner {
    public static void main(String[] args) {
        Account acc = new Account();
        Account accc = new Account(10000);
      
        acc.deposit(1000);
        acc.withdraw(2000);

        accc.deposit(1000);
        accc.withdraw(2000);
    }

}
