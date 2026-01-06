
package ItemInventory;

import java.util.ArrayList;
import java.util.List;

// Base class
class Item {
    String name;
    int price;

    Item(String name, int price) {
        this.name = name;
        this.price = price;
    }

    public String toString() {
        return "Item{name='" + name + "', price=" + price + "}";
    }
}

// Subclasses
class Book extends Item {
    String author_name;

    Book(String name, int price, String author_name) {
        super(name, price);
        this.author_name = author_name;
    }

    public String toString() {
        return "Book{name='" + name + "', price=" + price + ", author_name='" + author_name + "'}";
    }
}

class Laptop extends Item {
    String brand;

    Laptop(String name, int price, String brand) {
        super(name, price);
        this.brand = brand;
    }

    public String toString() {
        return "Laptop{name='" + name + "', price=" + price + ", brand='" + brand + "'}";
    }
}

class Mobile extends Item {
    String model_no;

    Mobile(String name, int price, String model_no) {
        super(name, price);
        this.model_no = model_no;
    }

    public String toString() {
        return "Mobile{name='" + name + "', price=" + price + ", model_no='" + model_no + "'}";
    }
}

// Generic Inventory
class Inventory<T extends Item> {
    ArrayList<T> items;

    Inventory() {
        items = new ArrayList<T>();
    }

    void addItem(T item) {
        items.add(item);
    }

    void displayItems() {
        for (T item : items) {
            System.out.println(item);
        }
    }

    // as required: calculateTotalPrice(List<T> items)
    int calculateTotalPrice(List<T> items) {
        int total = 0;
        for (T item : items) {
            total += item.price;
        }
        return total;
    }
}

public class Runner {
    public static void main(String[] args) {
        // ----- Inventory of Books -----
        Inventory<Book> bookInventory = new Inventory<Book>();
        Book b1 = new Book("Java Basics", 500, "John Doe");
        Book b2 = new Book("OOP in Java", 700, "Jane Smith");
        bookInventory.addItem(b1);
        bookInventory.addItem(b2);

        System.out.println("Books in Inventory:");
        bookInventory.displayItems();
        int totalBooks = bookInventory.calculateTotalPrice(bookInventory.items);
        System.out.println("Total price of Books: " + totalBooks);

        System.out.println();

        // ----- Inventory of Laptops ----- 
        Inventory<Laptop> laptopInventory = new Inventory<Laptop>();
        Laptop l1 = new Laptop("Dell XPS 13", 1500, "Dell");
        Laptop l2 = new Laptop("HP Envy", 1200, "HP");
        laptopInventory.addItem(l1);
        laptopInventory.addItem(l2);

        System.out.println("Laptops in Inventory:");
        laptopInventory.displayItems();
        int totalLaptops = laptopInventory.calculateTotalPrice(laptopInventory.items);
        System.out.println("Total price of Laptops: " + totalLaptops);

        // (Optional) You can also create a Mobile inventory similarly if needed.
        // Inventory<Mobile> mobileInventory = new Inventory<Mobile>();
        // mobileInventory.addItem(new Mobile("iPhone", 1000, "A2407"));
    }
}
