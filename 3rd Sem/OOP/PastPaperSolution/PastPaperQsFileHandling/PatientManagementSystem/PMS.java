import java.io.*;
import java.util.*;

enum Severity {
    LOW, MODERATE, SEVERE, CRITICAL
}

class Patient {
    String id;
    String name;
    int age;
    String diagnosis;
    String treatment;
    Severity severity;

    Patient(String id, String name, int age, String diagnosis, String treatment, Severity severity) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.diagnosis = diagnosis;
        this.treatment = treatment;
        this.severity = severity;
    }

    public String toString() {
        return id + "," + name + "," + age + "," + diagnosis + "," + treatment + "," + severity;
    }
}

public class PMS {
    static File file = new File("patients.txt");

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("\n1. Add Patient");
            System.out.println("2. View All Patients");
            System.out.println("3. Search Patient by ID");
            System.out.println("4. Update Diagnosis/Treatment");
            System.out.println("5. Exit");
            System.out.print("Choose: ");
            int choice = sc.nextInt();
            sc.nextLine(); // consume newline

            if (choice == 1) {
                System.out.print("Enter Patient ID: ");
                String id = sc.nextLine();
                System.out.print("Enter Name: ");
                String name = sc.nextLine();
                System.out.print("Enter Age: ");
                int age = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter Diagnosis: ");
                String diagnosis = sc.nextLine();
                System.out.print("Enter Treatment: ");
                String treatment = sc.nextLine();
                System.out.print("Enter Severity (LOW, MODERATE, SEVERE, CRITICAL): ");
                String sev = sc.nextLine().toUpperCase();

                Patient p = new Patient(id, name, age, diagnosis, treatment, Severity.valueOf(sev));
                addPatient(p);
                System.out.println("Patient added successfully!");

            } else if (choice == 2) {
                viewPatients();

            } else if (choice == 3) {
                System.out.print("Enter Patient ID to search: ");
                String id = sc.nextLine();
                Patient p = searchPatient(id);
                if (p != null) {
                    System.out.println("Found: " + p.toString());
                } else {
                    System.out.println("Patient not found.");
                }

            } else if (choice == 4) {
                System.out.print("Enter Patient ID to update: ");
                String id = sc.nextLine();
                System.out.print("Enter new Diagnosis: ");
                String newDiagnosis = sc.nextLine();
                System.out.print("Enter new Treatment: ");
                String newTreatment = sc.nextLine();
                updatePatient(id, newDiagnosis, newTreatment);

            } else if (choice == 5) {
                System.out.println("Exiting...");
                break;
            } else {
                System.out.println("Invalid choice!");
            }
        }
        sc.close();
    }

    static void addPatient(Patient p) {
        try {
            FileWriter fw = new FileWriter(file, true);
            fw.write(p.toString() + "\n");
            fw.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static void viewPatients() {
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }
            br.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static Patient searchPatient(String id) {
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts[0].equals(id)) {
                    br.close();
                    return new Patient(parts[0], parts[1], Integer.parseInt(parts[2]), parts[3], parts[4], Severity.valueOf(parts[5]));
                }
            }
            br.close();
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
        return null;
    }

    static void updatePatient(String id, String newDiagnosis, String newTreatment) {
        try {
            File tempFile = new File("temp.txt");
            BufferedReader br = new BufferedReader(new FileReader(file));
            BufferedWriter bw = new BufferedWriter(new FileWriter(tempFile));
            String line;
            boolean updated = false;

            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts[0].equals(id)) {
                    parts[3] = newDiagnosis;
                    parts[4] = newTreatment;
                    line = String.join(",", parts);
                    updated = true;
                }
                bw.write(line + "\n");
            }
            br.close();
            bw.close();
            file.delete();
            tempFile.renameTo(file);

            if (updated) {
                System.out.println("Patient updated successfully!");
            } else {
                System.out.println("Patient not found.");
            }
        } catch (IOException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
