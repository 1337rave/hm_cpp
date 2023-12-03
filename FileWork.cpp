// FileWork.cpp
#include "FileWork.h"
#include <iostream>

void FileWork::saveEmployeeToFile(const Employee& employee, std::ofstream& file) {
    file << employee.lastName << " " << employee.firstName << " " << employee.age << std::endl;
}

FileWork::FileWork(const std::string& filename) : filename(filename), employees(nullptr), numberOfEmployees(0) {
    loadFromFile();  // Завантаження списку співробітників з файлу при створенні об'єкта
}

FileWork::~FileWork() {
    saveToFile();  // Збереження списку співробітників у файл при знищенні об'єкта
    delete[] employees;  // Звільнення пам'яті масиву
}

void FileWork::addEmployee(const Employee& employee) {
    // Додавання співробітника до масиву (збільшення розміру масиву)
    Employee* newEmployees = new Employee[numberOfEmployees + 1];
    for (int i = 0; i < numberOfEmployees; ++i) {
        newEmployees[i] = employees[i];
    }
    newEmployees[numberOfEmployees] = employee;
    delete[] employees;
    employees = newEmployees;
    ++numberOfEmployees;
}

void FileWork::removeEmployee(const std::string& lastName) {
    // Видалення співробітника з масиву (зменшення розміру масиву)
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].lastName == lastName) {
            for (int j = i; j < numberOfEmployees - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            --numberOfEmployees;
            break;
        }
    }
}

Employee FileWork::findEmployee(const std::string& lastName) {
    // Пошук співробітника за прізвищем у масиві
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].lastName == lastName) {
            return employees[i];
        }
    }
    // Повернення пустого об'єкта Employee, якщо не знайдено
    return Employee();
}

void FileWork::findEmployeesByAge(int age) {
    // Пошук співробітників за віком у масиві
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].age == age) {
            std::cout << "Employee found: " << employees[i].lastName << " " << employees[i].firstName << " " << employees[i].age << std::endl;
        }
    }
}

void FileWork::findEmployeesByFirstLetter(char firstLetter) {
    // Пошук співробітників за першою літерою прізвища у масиві
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (!employees[i].lastName.empty() && employees[i].lastName[0] == firstLetter) {
            std::cout << "Employee found: " << employees[i].lastName << " " << employees[i].firstName << " " << employees[i].age << std::endl;
        }
    }
}

void FileWork::saveToFile() {
    // Збереження списку співробітників у файл
    std::ofstream file(filename);
    for (int i = 0; i < numberOfEmployees; ++i) {
        saveEmployeeToFile(employees[i], file);
    }
    file.close();
}

void FileWork::loadFromFile() {
    // Завантаження списку співробітників з файлу
    std::ifstream file(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            Employee employee;
            file >> employee.lastName >> employee.firstName >> employee.age;
            if (!file.fail()) {
                addEmployee(employee);
            }
        }
        file.close();
    }
}
