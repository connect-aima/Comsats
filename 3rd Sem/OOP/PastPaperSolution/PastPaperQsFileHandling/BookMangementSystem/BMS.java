package BookMangementSystem;
import java.io.*;
import java.util.*;
enum Status{
    AVAILABLE,
    BORROWED
}
class Book{
    String id;
    String name;
    Status status;

    Book(String id, String name, Status status){
        this.id = id;
        this.name = name;
        this.status = status;
    }
    public String toString(){
        return id + "," + name + "," + status;
    }
}
public class BMS {
    public static void main(String[] args) {
        File bookFile = new File("books.txt");
        Scanner sc = new Scanner(System.in);
        while(true){
            System.out.println("\n1. Add Book");
            System.out.println("2. Borrow Book");
            System.out.println("3. Delete Book");
            System.out.print("Choose: ");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            if(choice == 1){
                System.out.print("Enter Book ID: ");
                String id = sc.nextLine();
                System.out.print("Enter Book Name: ");
                String name = sc.nextLine();
                Book newBook = new Book(id, name, Status.AVAILABLE);
                try{
                    BufferedWriter bw = new BufferedWriter(new FileWriter(bookFile, true));
                    bw.write(newBook.toString() + "\n");
                    bw.close();
                    System.out.println("Book added successfully!");
                }catch(IOException e){
                    e.printStackTrace();
                }
            }else if(choice == 2){
                System.out.print("Enter Book ID to borrow: ");
                String idToBorrow = sc.nextLine();
                List<Book> books = new ArrayList<>();
                try{
                    BufferedReader br = new BufferedReader(new FileReader(bookFile));
                    String line;
                    while((line = br.readLine()) != null){
                        String[] parts = line.split(",");
                        Book book = new Book(parts[0], parts[1], Status.valueOf(parts[2]));
                        books.add(book);
                    }
                    br.close();

                    boolean found = false;
                    for(Book book : books){
                        if(book.id.equals(idToBorrow)){
                            found = true;
                            if(book.status == Status.AVAILABLE){
                                book.status = Status.BORROWED;
                                System.out.println("Book borrowed successfully!");
                            }else{
                                System.out.println("Book is already borrowed!");
                            }
                            break;
                        }
                    }
                    if(!found){
                        System.out.println("Book ID not found!");
                    }

                    BufferedWriter bw = new BufferedWriter(new FileWriter(bookFile));
                    for(Book book : books){
                        bw.write(book.toString() + "\n");
                    }
                    bw.close();
                }catch(IOException e){
                    e.printStackTrace();
                }

            }else if(choice == 3){
                System.out.print("Enter Book ID to delete: ");
                String idToDelete = sc.nextLine();
                List<Book> books = new ArrayList<>();
                try{
                    BufferedReader br = new BufferedReader(new FileReader(bookFile));
                    String line;
                    while((line = br.readLine()) != null){
                        String[] parts = line.split(",");
                        Book book = new Book(parts[0], parts[1], Status.valueOf(parts[2]));
                        books.add(book);
                    }
                    br.close();

                    boolean found = false;
                    for(Book book : books){
                        if(book.id.equals(idToDelete)){
                            found = true;
                            books.remove(book);
                            System.out.println("Book deleted successfully!");
                            break;
                        }
                    }
                    if(!found){
                        System.out.println("Book ID not found!");
                    }

                    BufferedWriter bw = new BufferedWriter(new FileWriter(bookFile));
                    for(Book book : books){
                        bw.write(book.toString() + "\n");
                    }
                    bw.close();
                }catch(IOException e){
                    e.printStackTrace();
                }
            }
        }
    }
}