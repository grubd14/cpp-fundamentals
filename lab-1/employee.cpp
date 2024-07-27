//A program with data members like emp_id, emp_name, emp_salary
//and displayDetails as a member function

#include <iostream>

using namespace std;

class Employee {
private:
  string emp_id;
  string emp_name;
  double emp_salary;

public:
  Employee (string id, string name, double salary) {
    emp_id = id;
    emp_name = name;
    emp_salary = salary;
  };

  void display_details() {
    cout << "Employee ID: " << emp_id << endl;
    cout << "Employee Name: " << emp_name << endl;
    cout << "Employee Salary: " << emp_salary << endl;
  }
};

int main() {
  Employee e1("A200", "Sushil Neupane", 45000.34);
  e1.display_details();
}
