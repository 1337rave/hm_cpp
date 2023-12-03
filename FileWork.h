#ifndef FILEWORK_H
#define FILEWORK_H

#include "Pen.h"

class FileWork {
public:
    FileWork(const std::string& filename);
    ~FileWork();

    void addEmployee(const Employee& employee);
    void removeEmployee(const string& lastName);
    Employee findEmployee(const string& lastName);
    void findEmployeesByAge(int age);
    void findEmployeesByFirstLetter(char firstLetter);
    void saveToFile();
    void loadFromFile();

private:
    string filename;
    Employee* employees;  
    int numberOfEmployees; 

    void saveEmployeeToFile(const Employee& employee, std::ofstream& file);
};

#endif // FILEWORK_H