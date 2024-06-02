/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#include "IssueTrackingSystem.h"
#include "Employee.h"
#include <iostream>
#include <string>

IssueTrackingSystem::IssueTrackingSystem () {
    currentEmps = 0;
    employees = nullptr;
}

IssueTrackingSystem::~IssueTrackingSystem () {
    delete[] employees;
}

void IssueTrackingSystem::deployEmployeeArray(int changeSize) {    
    if (currentEmps + changeSize > 0) {
        Employee* temp = employees;
        employees = new Employee[currentEmps + changeSize];
        int carrySize;
        if (changeSize > 0) {
            carrySize = currentEmps;
        } else {
            carrySize = currentEmps + changeSize;
        }
        for (int i = 0; i < carrySize; i++) {
            employees[i] = temp[i];
        }
        delete[] temp;
        currentEmps += changeSize;
    } else {
        currentEmps = 0;
        if (employees != nullptr) delete[] employees;
        employees = nullptr;
    }
}

Employee* IssueTrackingSystem::findEmployee(const string name) const {
    Employee* emp = nullptr; 
    for (int i = 0; i < currentEmps; i++) {
        if (employees[i].getName() == name) {
            emp = employees + i;
        }
    }
    return emp;
}

void IssueTrackingSystem::addEmployee(const string name, const string title) {
    if (findEmployee(name) == nullptr) {
        deployEmployeeArray(1);
        Employee newEmployee(name, title);
        employees[currentEmps - 1] = newEmployee; 
        cout << "Added employee " << name << "." << endl;
    } else {
        cout << "Cannot add employee. Employee with name " << name << " already exists." << endl;
    }
}

void IssueTrackingSystem::showEmployee(const string name) const {
    Employee* emp = findEmployee(name);
    if (emp != nullptr) {
        cout << emp->details() << endl;
    } else {
        cout << "Cannot show employee. There is no employee with name " << name << "." << endl;
    }
}

void IssueTrackingSystem::removeEmployee(const string name) {
    int removeIndex = -1;
    for (int i = 0; i < currentEmps; i++) {
       if (employees[i].getName() == name) {
           removeIndex = i;
           break;
       }
    }
    if (removeIndex > -1) {
        if (employees[removeIndex].getIssueCount() == 0) {
            for (int i = removeIndex; i < currentEmps - 1; i++) {
               employees[i] = employees[i+1];
            }
            deployEmployeeArray(-1);
            cout << "Removed employee " << name << "." << endl;
        } else {
            cout << "Cannot remove employee. " << name << " has assigned issues." << endl;
        }
    } else {
        cout << "Cannot remove employee. There is no employee with name " << name << "." << endl;
    }
}

void IssueTrackingSystem::addIssue (const int id, const string description, const string assigneeName) {
    Issue* issue;
    for (int i = 0; i < currentEmps; i++) {
        issue = employees[i].findIssue(id);
        if (issue != nullptr) {
            break;
        }
    } 
    Employee* emp = findEmployee(assigneeName);
    if (emp != nullptr) {
        if (issue == nullptr) {
            Issue issue(id, description);
            emp->addIssue(issue);
            cout << "Added issue " << id << "." << endl;
        } else {
            cout << "Cannot add issue. Issue with ID " << id << " already exists." << endl; 
        }
    } else {
        cout << "Cannot add issue. There is no employee with name " << assigneeName << "." << endl;
    }
}

void IssueTrackingSystem::removeIssue(const int issueId) {
    bool removed = false;
    for (int i = 0; i < currentEmps; i++) {
        if (employees[i].removeIssue(issueId)) {
           removed = true;
        }
    }
    if (removed) {
        cout << "Removed issue " << issueId << "." << endl;
    } else {
        cout << "Cannot remove issue. There is no issue with ID " << issueId << "." << endl;
    }
}

void IssueTrackingSystem::showIssue(const int issueId) const {
    Issue* issue;
    string nameOfEmployee;
    for (int i = 0; i < currentEmps; i++) {
        issue = employees[i].findIssue(issueId);
        if (issue != nullptr) {
            nameOfEmployee = employees[i].getName();
            break;
        }
    }
    if (issue != nullptr) {
        cout << issue->details(nameOfEmployee);
    } else {
        cout << "Cannot show issue. There is no issue with ID " << issueId << "." << endl;
    }
}

void IssueTrackingSystem::changeAssignee(const string previousAssignee, const string nextAssignee) {
    Employee* next = findEmployee(nextAssignee);
    Employee* prev = findEmployee(previousAssignee);
    if (next != nullptr && prev != nullptr) {
        prev->transferIssuesTo(next);
        cout << previousAssignee <<"'s issues are transferred to " << nextAssignee << "." << endl;
    } else {
        cout << "Cannot change assignee. Previous or/and new assignee does not exist." << endl;
    }
}

void IssueTrackingSystem::showAllEmployees() const {
    cout << "Employees in the system:" << endl;
    if (currentEmps == 0) {
        cout << "None" << endl;
    } else {
        for (int i = 0; i < currentEmps; i++) {
            cout << employees[i].details() << endl;
        }
    }
}

void IssueTrackingSystem::showAllIssues() const {
    cout << "Issues in the system:" << endl;
    bool foundIssue = false;
    for (int i = 0; i < currentEmps; i++) {
        string issueDetails = employees[i].issueDetails();
        if (issueDetails != "") {
            foundIssue = true;
            cout << employees[i].issueDetails();
        }
    }
    if (!foundIssue) {
        cout << "None" << endl;
    }
}
