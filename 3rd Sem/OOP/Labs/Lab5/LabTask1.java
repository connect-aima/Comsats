class Address {
    private String streetNo;
    private String houseNo;
    private String city;
    private String code;

  
    public Address(String streetNo, String houseNo, String city, String code) {
        this.streetNo = streetNo;
        this.houseNo = houseNo;
        this.city = city;
        this.code = code;
    }

   
    public String getStreetNo() {
        return streetNo;
    }

    public String getHouseNo() {
        return houseNo;
    }

    public String getCity() {
        return city;
    }

    public String getCode() {
        return code;
    }

    // Setters
    public void setStreetNo(String streetNo) {
        this.streetNo = streetNo;
    }

    public void setHouseNo(String houseNo) {
        this.houseNo = houseNo;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setCode(String code) {
        this.code = code;
    }

    // Method to display full address
    public void displayAddress() {
        System.out.println("Street#: " + streetNo + ", House#: " + houseNo +
                           ", City: " + city + ", Code: " + code);
    }
}


class Person {
    private String name;
    private Address address;  // Composition: Person "has an" Address

    // Constructor
    public Person(String name, Address address) {
        this.name = name;
        this.address = address;
    }

    // Getters
    public String getName() {
        return name;
    }

    public Address getAddress() {
        return address;
    }

    // Setters
    public void setName(String name) {
        this.name = name;
    }

    public void setAddress(Address address) {
        this.address = address;
    }

    // Display person details
    public void displayPerson() {
        System.out.println("Name: " + name);
        System.out.print("Address: ");
        address.displayAddress();
    }
}


public class LabTask1 {
    public static void main(String[] args) {
        // Create an Address object
        Address addr = new Address("12", "45B", "Lahore", "54000");

        // Create a Person object with Address
        Person p = new Person("Ali Khan", addr);

        // Display details
        p.displayPerson();

        // Update address using setters
        p.getAddress().setCity("Karachi");
        p.getAddress().setCode("74000");

        System.out.println("\nAfter updating address:");
        p.displayPerson();
    }
}
