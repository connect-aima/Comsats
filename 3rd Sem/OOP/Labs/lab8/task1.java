interface Shape {
    double getArea();
}

class Circle implements Shape {
    double pi = 3.14;
    int r = 3;

    @Override
    public double getArea() {
        return pi * r * r;
    }

}

class Rectangle implements Shape {
    int l = 3;
    int b = 3;

    @Override
    public double getArea() {
        return l * b;
    }
}

public class task1 {
    public static void main(String[] args) {
        Circle c1 = new Circle();
        Rectangle r1 = new Rectangle();
        Double areaOfCircle = c1.getArea();
        Double areaOfRec = r1.getArea();
        System.out.println("Area of circle and reactangle is " + areaOfCircle + " and " + areaOfRec + " respectively");
    }
}
