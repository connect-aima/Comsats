import java.io.InputStreamReader;   // Converts byte stream to character stream
import java.io.FileReader;          // Reads characters directly from a file
import java.io.BufferedReader;      // Adds buffering and readLine() support
import java.io.IOException;         // Handles I/O related exceptions
public class main {
    public static void main(String[] args) {
        //inputstreamreader reads bytes from inputstream and converts them to characters
    try (InputStreamReader isr = new InputStreamReader(System.in)) {

            System.out.println("InputStreamReader: Type text (Ctrl+D / Ctrl+Z to end)");

            int data = isr.read();     // Reads ONE character as int

            while (data != -1) {       // -1 indicates End Of Stream (EOF)
                char ch = (char) data; // Convert int to character
                System.out.print(ch);  // Print character
                data = isr.read();     // Read next character
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
//FileReader reads characters from a file directly
        try (FileReader fr = new FileReader("test.txt")) {

            System.out.println("\nFileReader output:");

            int data = fr.read();      

            while (data != -1) {       
                char ch = (char) data;
                System.out.print(ch);
                data = fr.read();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
//BufferedReader adds buffering below program taking bytes input converting to 
// characters using InputStreamReader and reading line by line using readLine()
//  method of BufferedReader
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {

            System.out.println("\nBufferedReader + InputStreamReader:");
            System.out.println("Type text (Ctrl+D / Ctrl+Z to end)");

            String line = br.readLine();   // Reads one full line

            while (line != null) {         // null indicates EOF
                System.out.println(line);
                line = br.readLine();      // Read next line
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
//BufferedReader adds buffering below program reading characters from a file and reading line by line using readLine()
//  method of BufferedReader
        try (BufferedReader br =new BufferedReader(new FileReader("test.txt"))) {

            System.out.println("\nBufferedReader + FileReader:");

            String line = br.readLine();

            while (line != null) {
                System.out.println(line);
                line = br.readLine();
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
