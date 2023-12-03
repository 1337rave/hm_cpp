#include "FileWork.h"
#include <iostream>

int main() {
    FileWork fileWork("employees.txt");

    int choice;
    do {
        cout << "Menu:" << std::endl;
        cout << "1. Add a new employee" << endl;
        cout << "2. Remove an employee" << endl;
        cout << "3. Find an employee by last name" << endl;
        cout << "4. Display information about all employees" << endl;
        cout << "0. Exit the program" << std::endl;

        cout << "Your choice: ";
        cin >> choice;

        // Process user choice
        switch (choice) {
        case 1: {
            // Add a new employee
            Employee newEmployee;
            cout << "Last Name: ";
            cin >> newEmployee.lastName;
            cout << "First Name: ";
            cin >> newEmployee.firstName;
            cout << "Age: ";
            cin >> newEmployee.age;

            fileWork.addEmployee(newEmployee);
            cout << "Employee added!" << endl;
            break;
        }
        case 2: {
            // Remove an employee
            string lastName;
            cout << "Enter last name to remove: ";
            cin >> lastName;

            fileWork.removeEmployee(lastName);
            cout << "Employee removed!" << endl;
            break;
        }
        case 3: {
            // Find an employee by last name
            string lastName;
            cout << "Enter last name to search: ";
            cin >> lastName;

            Employee foundEmployee = fileWork.findEmployee(lastName);
            if (!foundEmployee.lastName.empty()) {
                cout << "Found Employee: " << foundEmployee.lastName << " " << foundEmployee.firstName << " " << foundEmployee.age << endl;
            }
            else {
                cout << "Employee with last name '" << lastName << "' not found." << endl;
            }
            break;
        }
        case 4: {
            // Display information about all employees
            fileWork.findEmployeesByAge(0);  // Display all employees
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
