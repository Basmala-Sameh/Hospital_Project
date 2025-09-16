#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Staff.h"
#include "HospitalSystem.h"

using namespace std;

void showMenu() {
     cout << "\n\t\t\t\t*================team1=================*\n";
    cout << "\n\t\t\t\t*=======================================*\n";
    cout << "\t\t\t\t|   Hospital Management System          |\n";
    cout << "\t\t\t\t*=======================================*\n";
    cout << "\t\t\t\t|  1. Add Patient                       |\n";
    cout << "\t\t\t\t|  2. Update Patient                    |\n";
    cout << "\t\t\t\t|  3. Delete Patient                    |\n";
    cout << "\t\t\t\t|  4. Search Patient                    |\n";
    cout << "\t\t\t\t|  5. View All Patients                 |\n";
    cout << "\t\t\t\t|  6. Add Doctor                        |\n";
    cout << "\t\t\t\t|  7. View All Doctors                  |\n";
    cout << "\t\t\t\t|  8. Add Staff                         |\n";
    cout << "\t\t\t\t|  9. View All Staff                    |\n";
    cout << "\t\t\t\t|  10. Schedule Appointment             |\n";
    cout << "\t\t\t\t|  11. View Appointments                |\n";
    cout << "\t\t\t\t|  12. Cancel Appointment               |\n";
    cout << "\t\t\t\t|  13. Save Data                        |\n";
    cout << "\t\t\t\t|  14. Load Data                        |\n";
    cout << "\t\t\t\t|  0. Exit                              |\n";
    cout << "\t\t\t\t*=======================================*\n";
    cout << "\n\t\t\t\tChoose option: ";
}


int main() {
    HospitalSystem hospital;
    int choice;

    do {
        showMenu();
        cin >> choice;
         system("cls");
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
