// Create a class named Movie that can be used with your video rental business. The Movie class should 
// track the Motion Picture Association of America (MPAA) rating (e.g., Rated G, PG-13, R), ID Number, 
// and movie title with appropriate accessor and mutator methods. Also create an equals() method that 
// overrides Object ’s equals() method, where two movies are equal if their ID number is identical. Next, 
// create three additional classes named Action , Comedy , and Drama that are derived from Movie . 
// Finally, create an overridden method named calcLateFees that takes as input the number of days a movie 
// is late and returns the late fee for that movie. The default late fee is $2/day. Action movies have a late fee 
// of $3/day, comedies are $2.50/day, and dramas are $2/day. Test your classes from a main method. 


// Base class
class Movie {
    private String title;
    private String mpaaRating;
    private int idNumber;

    // Constructor
    public Movie(String title, String mpaaRating, int idNumber) {
        this.title = title;
        this.mpaaRating = mpaaRating;
        this.idNumber = idNumber;
    }

    // Accessors (getters)
    public String getTitle() {
        return title;
    }

    public String getMpaaRating() {
        return mpaaRating;
    }

    public int getIdNumber() {
        return idNumber;
    }

    // Mutators (setters)
    public void setTitle(String title) {
        this.title = title;
    }

    public void setMpaaRating(String mpaaRating) {
        this.mpaaRating = mpaaRating;
    }

    public void setIdNumber(int idNumber) {
        this.idNumber = idNumber;
    }

   
    public double calcLateFees(int daysLate) {
        return daysLate * 2.0;
    }

   
    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;

        if (obj == null || getClass() != obj.getClass())
            return false;

        Movie other = (Movie) obj;
        return this.idNumber == other.idNumber;
    }

   
    @Override
    public String toString() {
        return "Movie ID: " + idNumber +
                ", Title: " + title +
                ", Rating: " + mpaaRating;
    }
}

class Action extends Movie {

    public Action(String title, String mpaaRating, int idNumber) {
        super(title, mpaaRating, idNumber);
    }

    @Override
    public double calcLateFees(int daysLate) {
        return daysLate * 3.0; 
    }
}

class Comedy extends Movie {

    public Comedy(String title, String mpaaRating, int idNumber) {
        super(title, mpaaRating, idNumber);
    }

    @Override
    public double calcLateFees(int daysLate) {
        return daysLate * 2.5; 
    }
}

class Drama extends Movie {

    public Drama(String title, String mpaaRating, int idNumber) {
        super(title, mpaaRating, idNumber);
    }

    @Override
    public double calcLateFees(int daysLate) {
        return daysLate * 2.0; 
    }
}

public class Task1Runner {
    public static void main(String[] args) {
        Movie m1 = new Movie("Generic Movie", "PG", 101);
        Action a1 = new Action("Fast & Furious", "PG-13", 102);
        Comedy c1 = new Comedy("The Mask", "PG-13", 103);
        Drama d1 = new Drama("The Godfather", "R", 104);

       
        System.out.println(m1);
        System.out.println("Late fee (3 days): $" + m1.calcLateFees(3));

        System.out.println(a1);
        System.out.println("Late fee (3 days): $" + a1.calcLateFees(3));

        System.out.println(c1);
        System.out.println("Late fee (3 days): $" + c1.calcLateFees(3));

        System.out.println(d1);
        System.out.println("Late fee (3 days): $" + d1.calcLateFees(3));

        
        Movie m2 = new Movie("Duplicate ID", "PG", 101);
        System.out.println("\nAre m1 and m2 equal? " + m1.equals(m2));
    }
}

