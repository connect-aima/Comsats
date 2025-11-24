import java.util.ArrayList;
import java.util.Scanner;

class Contact {
    private String firstName;
    private String lastName;
    private String phone;
    private String email;

    public Contact(String firstName, String lastName, String phone, String email) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.phone = phone;
        this.email = email;
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getPhone() {
        return phone;
    }

    public String getEmail() {
        return email;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        return "Name: " + firstName + " " + lastName +
                "\nPhone: " + phone +
                "\nEmail: " + email + "\n";
    }

    public boolean matches(String text) {
        text = text.toLowerCase();
        return firstName.toLowerCase().contains(text) ||
                lastName.toLowerCase().contains(text) ||
                phone.toLowerCase().contains(text) ||
                email.toLowerCase().contains(text);
    }
}

public class ContactDatabase {

    public static void main(String[] args) {
        ArrayList<Contact> contacts = new ArrayList<>();
        Scanner in = new Scanner(System.in);

        while (true) {
            System.out.println("\n--- CONTACT DATABASE MENU ---");
            System.out.println("1. Add Contact");
            System.out.println("2. Display All Contacts");
            System.out.println("3. Search and Display");
            System.out.println("4. Search and Delete");
            System.out.println("5. Exit");
            System.out.print("Choose an option: ");
            int choice = in.nextInt();
            in.nextLine();
            switch (choice) {
                case 1:
                    System.out.print("First name: ");
                    String fn = in.nextLine();

                    System.out.print("Last name: ");
                    String ln = in.nextLine();

                    System.out.print("Phone number: ");
                    String ph = in.nextLine();

                    System.out.print("Email: ");
                    String em = in.nextLine();

                    contacts.add(new Contact(fn, ln, ph, em));
                    System.out.println("Contact added.");
                    break;

                case 2:
                    if (contacts.isEmpty()) {
                        System.out.println("No contacts to display.");
                    } else {
                        System.out.println("\n--- ALL CONTACTS ---");
                        for (Contact c : contacts) {
                            System.out.println(c);
                        }
                    }
                    break;

                case 3:
                    System.out.print("Enter search text: ");
                    String searchText = in.nextLine().toLowerCase();

                    boolean found = false;
                    for (Contact c : contacts) {
                        if (c.matches(searchText)) {
                            System.out.println("\n--- MATCH FOUND ---");
                            System.out.println(c);
                            found = true;
                        }
                    }

                    if (!found)
                        System.out.println("No contacts match your search.");
                    break;

                case 4:
                    System.out.print("Enter search text: ");
                    String delText = in.nextLine().toLowerCase();
                    Contact match = null;

                    for (Contact c : contacts) {
                        if (c.matches(delText)) {
                            match = c;
                            break;
                        }
                    }

                    if (match == null) {
                        System.out.println("No matching contact found.");
                    } else {
                        System.out.println("\n--- CONTACT FOUND ---");
                        System.out.println(match);
                        System.out.print("Delete this contact? (y/n): ");
                        String ans = in.nextLine();

                        if (ans.equalsIgnoreCase("y")) {
                            contacts.remove(match);
                            System.out.println("Contact deleted.");
                        } else {
                            System.out.println("Deletion cancelled.");
                        }
                    }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }

}
