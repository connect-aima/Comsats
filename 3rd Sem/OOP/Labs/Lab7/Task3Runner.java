// Create an abstract class that stores data about the shapes e.g. Number of Lines in a Shape, Pen Color, 
// Fill Color and an abstract method draw. Implement the method draw for Circle, Square and Triangle 
// subclasses, the better approach is to draw these figures on screen, if you can’t then just use a display 
// message in the draw function.
abstract class Shape {
    int lines;
    String color;

    Shape(int lines, String color) {
        this.lines = lines;
        this.color = color;
    }

    
    abstract void fillColor(String color);
    abstract void drawShape(int lines);
}

class Circle extends Shape {
    Circle(int lines, String color) {
        super(lines, color);
    }

    @Override
    void fillColor(String color) {
        System.out.println("Filling the Circle with color: " + color);
    }

    @Override
    void drawShape(int lines) {
        System.out.println("Drawing a Circle with " + lines + " lines (technically curved). Color: " + this.color);
    }
}

class Square extends Shape {
    Square(int lines, String color) {
        super(lines, color);
    }

    @Override
    void fillColor(String color) {
        System.out.println("Filling the Square with color: " + color);
    }

    @Override
    void drawShape(int lines) {
        System.out.println("Drawing a Square with " + lines + " lines. Color: " + this.color);
    }
}

class Triangle extends Shape {
    Triangle(int lines, String color) {
        super(lines, color);
    }

    @Override
    void fillColor(String color) {
        System.out.println("Filling the Triangle with color: " + color);
    }

    @Override
    void drawShape(int lines) {
        System.out.println("Drawing a Triangle with " + lines + " lines.Color: " + this.color);
    }
}

public class Task3Runner {
    public static void main(String[] args) {

        Shape c = new Circle(0, "Blue");
        c.drawShape(0);
        c.fillColor("Yellow");

        

        Shape s = new Square(4, "Red");
        s.drawShape(4);
        s.fillColor("Green");

      

        Shape t = new Triangle(3, "Black");
        t.drawShape(3);
        t.fillColor("Orange");
    }
}
