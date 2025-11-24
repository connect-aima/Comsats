
abstract class Vehicle {
   
    private String vehicleNumber;
    private String ownerName;

    public Vehicle(String vehicleNumber, String ownerName) {
        this.vehicleNumber = vehicleNumber;
        this.ownerName = ownerName;
    }

    public String getVehicleNumber() { return vehicleNumber; }
    public String getOwnerName() { return ownerName; }

    
    public abstract double calculateParkingFee(int hours);
}


class Car extends Vehicle {
    private final double firstHourFee = 50;
    private final double perHourRate = 30;

    public Car(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName);
    }

   
    @Override
    public double calculateParkingFee(int hours) {
        if (hours <= 1) return firstHourFee;
        return firstHourFee + (hours - 1) * perHourRate;
    }
}

class Bike extends Vehicle {
    private final double firstHourFee = 20;
    private final double perHourRate = 10;

    public Bike(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName);
    }

    @Override
    public double calculateParkingFee(int hours) {
        if (hours <= 1) return firstHourFee;
        return firstHourFee + (hours - 1) * perHourRate;
    }
}

class Truck extends Vehicle {
    private final double firstHourFee = 100;
    private final double perHourRate = 60;

    public Truck(String vehicleNumber, String ownerName) {
        super(vehicleNumber, ownerName);
    }

    @Override
    public double calculateParkingFee(int hours) {
        if (hours <= 1) return firstHourFee;
        return firstHourFee + (hours - 1) * perHourRate;
    }
}


class ParkingSlot {
   
    private Vehicle vehicle;

    public ParkingSlot(Vehicle vehicle) {
        this.vehicle = vehicle;
    }

    public void calculateAndDisplayFee(int hours) {
        double fee = vehicle.calculateParkingFee(hours);
        
        System.out.println("\nVehicle Number: " + vehicle.getVehicleNumber());
        System.out.println("Owner Name: " + vehicle.getOwnerName());
        System.out.println("Parked Hours: " + hours);
        System.out.println("Total Parking Fee: Rs. " + fee);
    }
}


public class SmartParkingSystem {
    public static void main(String[] args) {
       
        Vehicle car = new Car("CAR-123", "Ali");
        Vehicle bike = new Bike("BIKE-456", "Sara");
        Vehicle truck = new Truck("TRUCK-789", "Ahmed");

      
        ParkingSlot slot1 = new ParkingSlot(car);
        ParkingSlot slot2 = new ParkingSlot(bike);
        ParkingSlot slot3 = new ParkingSlot(truck);

        slot1.calculateAndDisplayFee(3);
        slot2.calculateAndDisplayFee(2);
        slot3.calculateAndDisplayFee(5);
    }
}
