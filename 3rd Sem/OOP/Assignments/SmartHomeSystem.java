import java.util.*;

abstract class SmartDevice {
    private String id;
    private String name;
    private boolean power;
    private String network;

    public SmartDevice(String id, String name) {
        this.id = id;
        this.name = name;
        this.power = false;
        this.network = "Not Connected";
    }

    public String getName() {
        return name;
    }

    public void connect(String network) {
        this.network = network;
        System.out.println(name + " connected to " + network);
    }

    public void turnOff() {
        power = false;
        System.out.println(name + " turned OFF.");
    }

    public abstract void turnOn();

    public abstract void showStatus();
}

class SmartLight extends SmartDevice {
    private int brightness = 0;

    public SmartLight(String id, String name) {
        super(id, name);
    }

    @Override
    public void turnOn() {
        brightness = 80;
        System.out.println(getName() + " turned ON with brightness " + brightness + "%");
    }

    @Override
    public void showStatus() {
        System.out.println("Light: " + getName() + " | Brightness: " + brightness + "%");
    }
}

class SmartFan extends SmartDevice {
    private int speed = 0;

    public SmartFan(String id, String name) {
        super(id, name);
    }

    @Override
    public void turnOn() {
        speed = 3;
        System.out.println(getName() + " turned ON at speed " + speed);
    }

    @Override
    public void showStatus() {
        System.out.println("Fan: " + getName() + " | Speed: " + speed);
    }
}

class SmartThermostat extends SmartDevice {
    private double temperature;
    private TemperatureSensor sensor;

    public SmartThermostat(String id, String name, double temp) {
        super(id, name);
        this.temperature = temp;
        this.sensor = new TemperatureSensor();
    }

    public void changeTemperature(double temp) {
        temperature = temp;
    }

    public void changeTemperature(double value, String unit) {
        if (unit.equalsIgnoreCase("F"))
            temperature = (value - 32) * 5 / 9;
        else
            temperature = value;
    }

    @Override
    public void turnOn() {
        System.out.println(getName() + " turned ON at " + temperature + "°C");
    }

    @Override
    public void showStatus() {
        System.out.println("Thermostat: " + getName() +
                " | Set Temp: " + temperature + "°C" +
                " | Sensor: " + sensor.readTemperature() + "°C");
    }

    private class TemperatureSensor {
        public double readTemperature() {
            return temperature + 0.5;
        }
    }
}

class CentralController {
    private List<SmartDevice> devices = new ArrayList<>();

    public void addDevice(SmartDevice d) {
        devices.add(d);
    }

    public void connectAll(String network) {
        for (SmartDevice d : devices)
            d.connect(network);
    }

    public void turnOnAll() {
        for (SmartDevice d : devices)
            d.turnOn();
    }

    public void showAllStatus() {
        for (SmartDevice d : devices)
            d.showStatus();
    }

    public void turnOffAll() {
        for (SmartDevice d : devices)
            d.turnOff();
    }
}

public class SmartHomeSystem {
    public static void main(String[] args) {
        CentralController controller = new CentralController();

        SmartLight light = new SmartLight("L1", "Living Room Light");
        SmartFan fan = new SmartFan("F1", "Bedroom Fan");
        SmartThermostat thermostat = new SmartThermostat("T1", "Main Thermostat", 22.0);

        controller.addDevice(light);
        controller.addDevice(fan);
        controller.addDevice(thermostat);

        controller.connectAll("Home_WiFi");
        controller.turnOnAll();

        thermostat.changeTemperature(77, "F");

        controller.showAllStatus();
        controller.turnOffAll();
    }
}
