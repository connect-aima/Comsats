class Fraction {
    private int numerator;
    private int denominator;

  
    public Fraction() {
        this.numerator = 0;
        this.denominator = 1;
    }

   
    public Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            System.out.println("Denominator cannot be zero! Setting to 1.");
            denominator = 1;
        }
        this.numerator = numerator;
        this.denominator = denominator;
    }

    
    public void display() {
        System.out.println(numerator + "/" + denominator);
    }

   
    public void equals(Fraction f) {
        if(this.numerator * f.denominator == this.denominator * f.numerator){
            System.out.println("Equal");
        }else{
           System.out.println("Not Equal");
        }
    }
}

