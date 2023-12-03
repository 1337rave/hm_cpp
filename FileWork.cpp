// FileWork.cpp
#include "FileWork.h"
#include <iostream>

void FileWork::saveEmployeeToFile(const Employee& employee, std::ofstream& file) {
    file << employee.lastName << " " << employee.firstName << " " << employee.age << std::endl;
}

FileWork::FileWork(const std::string& filename) : filename(filename), employees(nullptr), numberOfEmployees(0) {
    loadFromFile();  // ������������ ������ ����������� � ����� ��� �������� ��'����
}

FileWork::~FileWork() {
    saveToFile();  // ���������� ������ ����������� � ���� ��� ������� ��'����
    delete[] employees;  // ��������� ���'�� ������
}

void FileWork::addEmployee(const Employee& employee) {
    // ��������� ����������� �� ������ (��������� ������ ������)
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
    // ��������� ����������� � ������ (��������� ������ ������)
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
    // ����� ����������� �� �������� � �����
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].lastName == lastName) {
            return employees[i];
        }
    }
    // ���������� ������� ��'���� Employee, ���� �� ��������
    return Employee();
}

void FileWork::findEmployeesByAge(int age) {
    // ����� ����������� �� ���� � �����
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (employees[i].age == age) {
            std::cout << "Employee found: " << employees[i].lastName << " " << employees[i].firstName << " " << employees[i].age << std::endl;
        }
    }
}

void FileWork::findEmployeesByFirstLetter(char firstLetter) {
    // ����� ����������� �� ������ ������ ������� � �����
    for (int i = 0; i < numberOfEmployees; ++i) {
        if (!employees[i].lastName.empty() && employees[i].lastName[0] == firstLetter) {
            std::cout << "Employee found: " << employees[i].lastName << " " << employees[i].firstName << " " << employees[i].age << std::endl;
        }
    }
}

void FileWork::saveToFile() {
    // ���������� ������ ����������� � ����
    std::ofstream file(filename);
    for (int i = 0; i < numberOfEmployees; ++i) {
        saveEmployeeToFile(employees[i], file);
    }
    file.close();
}

void FileWork::loadFromFile() {
    // ������������ ������ ����������� � �����
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
