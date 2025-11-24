public class Distance {
    int inches, feet;

    public Distance() {
        feet = 100;
        inches = 300;
    }

    public Distance(int x, int y) {
        feet = x;
        inches = y;
    }

    public void displayDistance() {
        System.out.println("The Distance is : " + feet + " feet , " + inches + " inches");
    }
}


