import java.io.*;
import java.util.*;
enum SeverityLevel {
    LOW, MODERATE, SEVERE, CRITICAL
}

class Patient {
    String id;
    String name;
    int age;
    String diagnosis;
    String treatmentPlan;
    SeverityLevel severity;

    // Constructor
    Patient(String id, String name, int age, String diagnosis,
            String treatmentPlan, SeverityLevel severity) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.diagnosis = diagnosis;
        this.treatmentPlan = treatmentPlan;
        this.severity = severity;
    }

    // Convert Patient → String (for file storage)
    String toFileString() {
        return id + "," + name + "," + age + "," + diagnosis + ","
                + treatmentPlan + "," + severity;
    }

    // Convert String → Patient (from file)
    static Patient fromFileString(String line) {
        String[] parts = line.split(",");
        return new Patient(
                parts[0],
                parts[1],
                Integer.parseInt(parts[2]),
                parts[3],
                parts[4],
                SeverityLevel.valueOf(parts[5])
        );
    }

    // Display patient info
    void display() {
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Diagnosis: " + diagnosis);
        System.out.println("Treatment Plan: " + treatmentPlan);
        System.out.println("Severity: " + severity);
        System.out.println("---------------------------");
    }
}

public class PatientManagementSystem {

    static final String FILE_NAME = "PatientRecord.txt";
    static void addPatient(Patient p) {
        try (FileWriter writer = new FileWriter(FILE_NAME, true)) {
            writer.write(p.toFileString() + "\n");
            System.out.println("Patient record added successfully.");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // =======================
    // DISPLAY ALL PATIENTS
    // =======================
    static void displayAllPatients() {
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                Patient p = Patient.fromFileString(line);
                p.display();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    // =======================
    // SEARCH PATIENT BY ID
    // =======================
    static Patient searchPatientById(String searchId) {
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                Patient p = Patient.fromFileString(line);
                if (p.id.equals(searchId)) {
                    return p;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    // =======================
    // UPDATE PATIENT
    // =======================
    static void updatePatient(String searchId,
                              String newDiagnosis,
                              String newTreatmentPlan) {

        List<Patient> patients = new ArrayList<>();
        boolean found = false;

        // Read all patients
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = br.readLine()) != null) {
                Patient p = Patient.fromFileString(line);
                if (p.id.equals(searchId)) {
                    p.diagnosis = newDiagnosis;
                    p.treatmentPlan = newTreatmentPlan;
                    found = true;
                }
                patients.add(p);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        // Rewrite file
        try (FileWriter writer = new FileWriter(FILE_NAME)) {
            for (Patient p : patients) {
                writer.write(p.toFileString() + "\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        if (found) {
            System.out.println("Patient record updated successfully.");
        } else {
            System.out.println("Patient ID not found.");
        }
    }

    // =======================
    // MAIN MENU
    // =======================
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        new File(FILE_NAME); // ensure file exists

        while (true) {
            System.out.println("\n--- Patient Management System ---");
            System.out.println("1. Add Patient");
            System.out.println("2. Display All Patients");
            System.out.println("3. Search Patient by ID");
            System.out.println("4. Update Diagnosis/Treatment");
            System.out.println("5. Exit");
            System.out.print("Enter choice: ");

            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {

                case 1:
                    System.out.print("ID: ");
                    String id = sc.nextLine();

                    System.out.print("Name: ");
                    String name = sc.nextLine();

                    System.out.print("Age: ");
                    int age = sc.nextInt();
                    sc.nextLine();

                    System.out.print("Diagnosis: ");
                    String diagnosis = sc.nextLine();

                    System.out.print("Treatment Plan: ");
                    String treatment = sc.nextLine();

                    System.out.print("Severity (LOW/MODERATE/SEVERE/CRITICAL): ");
                    SeverityLevel severity =
                            SeverityLevel.valueOf(sc.nextLine().toUpperCase());

                    addPatient(new Patient(id, name, age, diagnosis, treatment, severity));
                    break;

                case 2:
                    displayAllPatients();
                    break;

                case 3:
                    System.out.print("Enter Patient ID: ");
                    Patient p = searchPatientById(sc.nextLine());
                    if (p != null) p.display();
                    else System.out.println("Patient not found.");
                    break;

                case 4:
                    System.out.print("Enter Patient ID: ");
                    String updateId = sc.nextLine();

                    System.out.print("New Diagnosis: ");
                    String newDiag = sc.nextLine();

                    System.out.print("New Treatment Plan: ");
                    String newTreat = sc.nextLine();

                    updatePatient(updateId, newDiag, newTreat);
                    break;

                case 5:
                    System.out.println("Exiting system.");
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}
