// made by :- 
// Abhyudai Chauhan -BTECH/25209/24
// Shreya -BTECH/25062/24
// Vansh Sachdeva -BTECH/25174/24


// program for hospital management system which manages   :-
//patients
//doctors
//appointments
//bills
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definitions
typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char disease[100];
} Patient;

typedef struct {
    int id;
    char name[100];
    char specialization[100];
} Doctor;

typedef struct {
    int patientId;
    int doctorId;
    char date[20];
} Appointment;

typedef struct {
    int patientId;
    float amount;
    char date[20];
} Bill;

// Global Arrays and Counters
Patient patients[100];
Doctor doctors[100];
Appointment appointments[100];
Bill bills[100];

int patientCount = 0, doctorCount = 0, appointmentCount = 0, billCount = 0;

// Function Declarations
void addPatient();
void viewPatients();
void addDoctor();
void viewDoctors();
void scheduleAppointment();
void viewAppointments();
void generateBill();
void viewBills();
void savePatients();
void loadPatients();
void saveDoctors();
void loadDoctors();
void saveAppointments();
void loadAppointments();
void saveBills();
void loadBills();


int main() {
    int choice;

    // Load Data from Files
    loadPatients();
    loadDoctors();
    loadAppointments();
    loadBills();

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. View Patients\n");
        printf("3. Add Doctor\n");
        printf("4. View Doctors\n");
        printf("5. Schedule Appointment\n");
        printf("6. View Appointments\n");
        printf("7. Generate Bill\n");
        printf("8. View Bills\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume newline character

        switch (choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: addDoctor(); break;
            case 4: viewDoctors(); break;
            case 5: scheduleAppointment(); break;
            case 6: viewAppointments(); break;
            case 7: generateBill(); break;
            case 8: viewBills(); break;
            case 9: 
                // Save Data Before Exiting
                savePatients();
                saveDoctors();
                saveAppointments();
                saveBills();
                printf("Exiting...\n");
                exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

// Function Implementations

void addPatient() {
    printf("Enter Patient ID: ");
    scanf("%d", &patients[patientCount].id);
    getchar();
    printf("Enter Name: ");
    fgets(patients[patientCount].name, 100, stdin);
    strtok(patients[patientCount].name, "\n");
    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);
    getchar();
    printf("Enter Gender: ");
    fgets(patients[patientCount].gender, 10, stdin);
    strtok(patients[patientCount].gender, "\n");
    printf("Enter Disease: ");
    fgets(patients[patientCount].disease, 100, stdin);
    strtok(patients[patientCount].disease, "\n");

    patientCount++;
    savePatients();
    printf("Patient added successfully!\n");
}

void viewPatients() {
    printf("\n--- Patient List ---\n");
    for (int i = 0; i < patientCount; i++) {
        printf("ID: %d, Name: %s, Age: %d, Gender: %s, Disease: %s\n",
               patients[i].id, patients[i].name, patients[i].age, patients[i].gender, patients[i].disease);
    }
}

void addDoctor() {
    printf("Enter Doctor ID: ");
    scanf("%d", &doctors[doctorCount].id);
    getchar();
    printf("Enter Name: ");
    fgets(doctors[doctorCount].name, 100, stdin);
    strtok(doctors[doctorCount].name, "\n");
    printf("Enter Specialization: ");
    fgets(doctors[doctorCount].specialization, 100, stdin);
    strtok(doctors[doctorCount].specialization, "\n");

    doctorCount++;
    saveDoctors();
    printf("Doctor added successfully!\n");
}

void viewDoctors() {
    printf("\n--- Doctor List ---\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("ID: %d, Name: %s, Specialization: %s\n",
               doctors[i].id, doctors[i].name, doctors[i].specialization);
    }
}

void scheduleAppointment() {
    printf("Enter Patient ID: ");
    scanf("%d", &appointments[appointmentCount].patientId);
    printf("Enter Doctor ID: ");
    scanf("%d", &appointments[appointmentCount].doctorId);
    getchar();
    printf("Enter Date (DD/MM/YYYY): ");
    fgets(appointments[appointmentCount].date, 20, stdin);
    strtok(appointments[appointmentCount].date, "\n");

    appointmentCount++;
    saveAppointments();
    printf("Appointment scheduled successfully!\n");
}

void viewAppointments() {
    printf("\n--- Appointments ---\n");
    for (int i = 0; i < appointmentCount; i++) {
        printf("Patient ID: %d, Doctor ID: %d, Date: %s\n",
               appointments[i].patientId, appointments[i].doctorId, appointments[i].date);
    }
}

void generateBill() {
    printf("Enter Patient ID: ");
    scanf("%d", &bills[billCount].patientId);
    printf("Enter Bill Amount: ");
    scanf("%f", &bills[billCount].amount);
    getchar();
    printf("Enter Date (DD/MM/YYYY): ");
    fgets(bills[billCount].date, 20, stdin);
    strtok(bills[billCount].date, "\n");

    billCount++;
    saveBills();
    printf("Bill generated successfully!\n");
}

void viewBills() {
    printf("\n--- Bills ---\n");
    for (int i = 0; i < billCount; i++) {
        printf("Patient ID: %d, Amount: %.2f, Date: %s\n",
               bills[i].patientId, bills[i].amount, bills[i].date);
    }
}

// File Handling Functions

void savePatients() {
    FILE *file = fopen("patients.dat", "wb");
    fwrite(&patientCount, sizeof(int), 1, file);
    fwrite(patients, sizeof(Patient), patientCount, file);
    fclose(file);
}

void loadPatients() {
    FILE *file = fopen("patients.dat", "rb");
    if (file) {
        fread(&patientCount, sizeof(int), 1, file);
        fread(patients, sizeof(Patient), patientCount, file);
        fclose(file);
    }
}

void saveDoctors() {
    FILE *file = fopen("doctors.dat", "wb");
    fwrite(&doctorCount, sizeof(int), 1, file);
    fwrite(doctors, sizeof(Doctor), doctorCount, file);
    fclose(file);
}

void loadDoctors() {
    FILE *file = fopen("doctors.dat", "rb");
    if (file) {
        fread(&doctorCount, sizeof(int), 1, file);
        fread(doctors, sizeof(Doctor), doctorCount, file);
        fclose(file);
    }
}

void saveAppointments() {
    FILE *file = fopen("appointments.dat", "wb");
    fwrite(&appointmentCount, sizeof(int), 1, file);
    fwrite(appointments, sizeof(Appointment), appointmentCount, file);
    fclose(file);
}

void loadAppointments() {
    FILE *file = fopen("appointments.dat", "rb");
    if (file) {
        fread(&appointmentCount, sizeof(int), 1, file);
        fread(appointments, sizeof(Appointment), appointmentCount, file);
        fclose(file);
    }
}

void saveBills() {
    FILE *file = fopen("bills.dat", "wb");
    fwrite(&billCount, sizeof(int), 1, file);
    fwrite(bills, sizeof(Bill), billCount, file);
    fclose(file);
}

void loadBills() {
    FILE *file = fopen("bills.dat", "rb");
    if (file) {
        fread(&billCount, sizeof(int), 1, file);
        fread(bills, sizeof(Bill), billCount, file);
        fclose(file);
    }
}


