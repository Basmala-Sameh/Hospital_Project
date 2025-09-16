#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "HospitalSystem.h"

using namespace std;

void showMenu() {
    cout << "\n===== Hospital Management System =====\n";
    cout << "1. Add Patient\n";
    cout << "2. Update Patient\n";
    cout << "3. Delete Patient\n";
    cout << "4. Search Patient\n";
    cout << "5. View All Patients\n";
    cout << "6. Add Doctor\n";
    cout << "7. View All Doctors\n";
    cout << "8. Add Staff\n";
    cout << "9. View All Staff\n";
    cout << "10. Schedule Appointment\n";
    cout << "11. View Appointments\n";
    cout << "12. Cancel Appointment\n";
    cout << "13. Save Data\n";
    cout << "14. Load Data\n";
    cout << "0. Exit\n";
    cout << "Choose option: ";
}

int main() {
    HospitalSystem hospital;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: hospital.addPatient(); break;
            case 2: hospital.updatePatient(); break;
            case 3: hospital.deletePatient(); break;
            case 4: hospital.searchPatient(); break;
            case 5: hospital.viewPatients(); break;
            case 6: hospital.addDoctor(); break;
            case 7: hospital.viewDoctors(); break;
            case 8: hospital.addStaff(); break;
            case 9: hospital.viewStaff(); break;
            case 10: hospital.scheduleAppointment(); break;
            case 11: hospital.viewAppointments(); break;
            case 12: hospital.cancelAppointment(); break;
            case 13: hospital.saveData(); break;
            case 14: hospital.loadData(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
