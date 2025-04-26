

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;


int writeFile(const string &filename) 
{
    ofstream ofs(filename);
    if (!ofs) 
    {
        cerr << "File Open Error\n";
        exit(1); 
    }



    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;
    ofs << numEmployees << endl; 

    cout << "Enter Employee ID, Name, Department, and Salary for each employee: \n";
    for (int i = 0; i < numEmployees; i++) 
    {
        int empID;
        string empName, deptName;
        double salary;

        cin >> empID >> empName >> deptName >> salary;


        ofs << empID << " " << empName << " " << deptName << " " << salary << endl;
    }

    ofs.close(); 

    return numEmployees;
}


int readFile(const string &filename) 
{
    ifstream ifs(filename);
    if (!ifs) 
    {
        cerr << "Error opening file " << filename << endl;
        exit(1);
    }




    int numEmployees;
    ifs >> numEmployees; 

    int empID;
    string empName, deptName;
    double salary, totalSalary = 0;

    cout << left << setw(20) << "ID"
         << setw(20) << "Name"
         << setw(20) << "Department"
         << "Salary" << endl;

    for (int i = 0; i < numEmployees; i++) {

        ifs >> empID >> empName >> deptName >> salary; 
        totalSalary += salary; 

    
        cout << left << setw(20) << empID
             << setw(20) << empName
             << setw(20) << deptName
             << salary << endl;
    }

    ifs.close(); 


    double averageSalary = totalSalary / numEmployees;
    cout << "\nTotal Salary: " << totalSalary << " Average Salary: " << averageSalary << endl;

    return numEmployees; 
}

