import java.io.*;
class employee implements Serializable {
    int id;
    String name;
    employee(int id, String name) {
        this.id = id;
        this.name = name;
    }
}
public class Serialization {
    public static void main(String[] args) {
        employee e1 = new employee(101, "John Doe");
        try {
            // Serialization->writing object to a file in form of byte stream
            FileOutputStream fileOut = new FileOutputStream("employee.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(e1);
            out.close();
            fileOut.close();
            System.out.println("Serialized data is saved in employee.ser");

            // Deserialization->reading object from a file in form of byte stream
            FileInputStream fileIn = new FileInputStream("employee.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            employee e2 = (employee) in.readObject();
            in.close();
            fileIn.close();

            System.out.println("Deserialized Employee...");
            System.out.println("ID: " + e2.id);
            System.out.println("Name: " + e2.name);
        } catch (IOException i) {
            i.printStackTrace();
        } catch (ClassNotFoundException c) {
            System.out.println("employee class not found");
            c.printStackTrace();
        }
    }
}
