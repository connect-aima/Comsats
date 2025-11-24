public class Runner2 {

    public static void main(String[] args) {
       
        Book book1 = new Book();
        book1.setAuthor("Aima");
        book1.setChapterNames(new String[] { "Intro", "OOP Basics", "Encapsulation" });

       
        String[] chapters = { "Preface", "Inheritance", "Polymorphism", "Abstraction" };
        Book book2 = new Book("Abdullah", chapters);

        
        if (book1.compareBooks(book2)) {
            System.out.println("Both books have the same author.");
        } else {
            System.out.println("Different authors.");
        }

       
        Book largerBook = book1.compareChapterNames(book2);
        System.out.println("Book with more chapters is written by: " + largerBook.getAuthor());
    }
}
