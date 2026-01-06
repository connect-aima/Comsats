
package CarShowRoom;
import java.io.*;
import java.util.*;

class Car implements Serializable {
    String model;
    String color;
    String regNo;
    Date manufactureDate;

    Car(String model, String color, String regNo, Date manufactureDate) {
        this.model = model;
        this.color = color;
        this.regNo = regNo;
        this.manufactureDate = manufactureDate;
    }

    public String toString() {
        return "Model: " + model + ", Color: " + color + ", RegNo: " + regNo + ", Manufacture Date: " + manufactureDate;
    }
}

class ShowRoom implements Serializable {
    Car[] carsArray;
    String owner;

    ShowRoom(Car[] carsArray, String owner) {
        this.carsArray = carsArray;
        this.owner = owner;
    }
}

public class showRoomApp {
    public static void main(String[] args) {
        // Create sample cars
        Car[] cars = {
            new Car("Model S", "Black", "ABC123", new Date(120, 5, 15)), // Year 2020
            new Car("Mustang", "Red", "XYZ789", new Date(117, 3, 10)),   // Year 2017
            new Car("Civic", "Black", "LMN456", new Date(121, 1, 20))    // Year 2021
        };

        ShowRoom showroom = new ShowRoom(cars, "John's Showroom");

        // Write showroom object to file
        try {
            ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("ShowRoom.ser"));
            oos.writeObject(showroom);
            oos.close();
            System.out.println("Showroom data saved successfully!");
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Read showroom object from file
        ShowRoom readShowroom = null;
        try {
            ObjectInputStream ois = new ObjectInputStream(new FileInputStream("ShowRoom.ser"));
            readShowroom = (ShowRoom) ois.readObject();
            ois.close();
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        if (readShowroom != null) {
            System.out.println("\nAll Cars:");
            for (Car car : readShowroom.carsArray) {
                System.out.println(car);
            }

            // A) Cars manufactured in last 5 years
            System.out.println("\nCars manufactured in last 5 years:");
            Date currentDate = new Date();
            for (Car car : readShowroom.carsArray) {
                if (currentDate.getYear() - car.manufactureDate.getYear() <= 5) {
                    System.out.println(car);
                }
            }

            // B) Delete cars with Black color
            System.out.println("\nDeleting cars with Black color...");
            List<Car> updatedCars = new ArrayList<>();
            for (Car car : readShowroom.carsArray) {
                if (!car.color.equalsIgnoreCase("Black")) {
                    updatedCars.add(car);
                }
            }

            // Update showroom and save again
            readShowroom.carsArray = updatedCars.toArray(new Car[0]);
            try {
                ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("ShowRoom.ser"));
                oos.writeObject(readShowroom);
                oos.close();
                System.out.println("Updated showroom saved successfully!");
            } catch (IOException e) {
                e.printStackTrace();
            }

            System.out.println("\nCars after deletion:");
            for (Car car : readShowroom.carsArray) {
                System.out.println(car);
            }
        }
    }
}
