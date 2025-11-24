import java.util.Scanner;

class Publication {
    protected String title;
    protected double price;

    public void set(String title, double price) {
        this.title = title;
        this.price = price;
    }

    public String getTitle() {
        return title;
    }

    public double getPrice() {
        return price;
    }

    public void display() {
        System.out.println("Title: " + title);
        System.out.println("Price: " + price);
    }
}


class Book extends Publication {
    private int pageCount;

    public void set(String title, double price, int pageCount) {
       
        super.set(title, price);
        this.pageCount = pageCount;
    }

    public int getPageCount() {
        return pageCount;
    }

    public void display() {
       
        super.display();
        System.out.println("Page Count: " + pageCount);
    }
}


class Tape extends Publication {
    private double playingTime; 

    public void set(String title, double price, double playingTime) {
        super.set(title, price);
        this.playingTime = playingTime;
    }

    public double getPlayingTime() {
        return playingTime;
    }

    public void display() {
        super.display();
        System.out.println("Playing Time: " + playingTime + " minutes");
    }
}


public class Task2Runner {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

       
        Book b = new Book();
        System.out.println("Enter Book Details:");
        System.out.print("Title: ");
        String bTitle = input.nextLine();
        System.out.print("Price: ");
        double bPrice = input.nextDouble();
        System.out.print("Page Count: ");
        int bPages = input.nextInt();
        input.nextLine(); 

        b.set(bTitle, bPrice, bPages);

       
        Tape t = new Tape();
        System.out.println("\nEnter Tape Details:");
        System.out.print("Title: ");
        String tTitle = input.nextLine();
        System.out.print("Price: ");
        double tPrice = input.nextDouble();
        System.out.print("Playing Time (in minutes): ");
        double tTime = input.nextDouble();

        t.set(tTitle, tPrice, tTime);

      
        System.out.println("\n Book Details ");
        b.display();

        System.out.println("\n Tape Details ");
        t.display();

        input.close();
    }
}

