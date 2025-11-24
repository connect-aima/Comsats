public class Marks {
    private int mark1, mark2, mark3;

    public Marks() {
        this.mark1 = 100;
        this.mark2 = 200;
        this.mark3 = 300;
    }
    public Marks(int x,int y, int z) {
        this.mark1 = x;
        this.mark2 = y;
        this.mark3 = z;
    }

    public void sum(){
    int sum = this.mark1+this.mark2+this.mark3;
      System.out.println("Sum:"+ sum);
    }

}

