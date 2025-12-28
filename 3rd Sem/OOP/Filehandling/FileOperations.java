import java.util.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class FileOperations {
    public static void main(String[] args) {
        //Creating a file
        try {
            File myFile = new File("test.txt");
            myFile.createNewFile();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        //writing to a file
        try {
            FileWriter writer = new FileWriter("test.txt");
            writer.write("I have written secret code here.");
            writer.close();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        //reading from a file
        try (BufferedReader br =new BufferedReader(new FileReader("test.txt"))) {
            String line = br.readLine();
            while (line != null) {
                System.out.println(line);
                line = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        //deleting a file
         try {
            File myFile = new File("random.txt");
            myFile.createNewFile();
            if (myFile.delete()) {
                System.out.println("Deleted the file: " + myFile.getName());
            } else {
                System.out.println("Failed to delete the file.");
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
