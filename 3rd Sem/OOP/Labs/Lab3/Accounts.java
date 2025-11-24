public class Accounts {
    private double balance ;
    public Accounts (){
        balance=20000;
    }
    public Accounts (double bal){
        setBalance(bal);
    }
    public void setBalance (double bal){
        if (bal>0){
            balance=bal;
        }
    }
    public void deposit(double amount){
        if (amount > 0){
            balance=balance+amount;
        }else{
            System.out.println("Please enter valid amount");
        }
    }
    public double getbalance(){
        return balance;
    }
    public void widrawAmount (double amount){
        if (amount > balance ){
            System.out.println("You Do not Have sufficient amount");
        }else{
            balance=balance-amount;
            System.out.println("Amount"+ amount +" has been widrawed And your remaining Balance is" + balance);
        }
    }
}
