public class Runner2 {
    public static void main(String[] args) {
        Accounts a = new Accounts();
        System.out.println( a.getbalance());
        a.deposit(1000);
        System.out.println( a.getbalance());
        a.widrawAmount(3000);
        System.out.println( a.getbalance());

        Accounts am = new Accounts(30000);
         System.out.println( am.getbalance());
        am.deposit(1000);
        System.out.println( am.getbalance());
        am.widrawAmount(3000);
        System.out.println( am.getbalance());
    }
}
