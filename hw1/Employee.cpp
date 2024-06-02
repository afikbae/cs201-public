/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#include "Employee.h"
#include "Issue.h"
#include <string>

Employee::Employee () 
: currentIssueCount(0) {
    name = "";
    title = "";
    assignedIssues = nullptr;
}

Employee::Employee (string name, string title)
: currentIssueCount(0) {
    this->name = name;
    this->title = title;
    assignedIssues = nullptr;
}

Employee::~Employee () { 
    if (assignedIssues != nullptr)
        delete[] assignedIssues; 
} 

Employee& Employee::operator=(Employee& rigth) { 
    name = rigth.name; 
    title = rigth.title; 
    currentIssueCount = rigth.currentIssueCount; 
    delete[] assignedIssues;
    if (currentIssueCount > 0) {
        assignedIssues = new Issue[currentIssueCount]; 
        for (int i = 0; i < currentIssueCount; i++) 
        { 
            assignedIssues[i] = rigth.assignedIssues[i]; 
        } 
    } else { 
        assignedIssues = nullptr;
    }
    return *this;
}

string Employee::getName () const {
    return this->name;
}

void Employee::deployIssueArray(int changeSize) {
    if (currentIssueCount + changeSize > 0) {
        Issue* temp = assignedIssues;
        assignedIssues = new Issue[currentIssueCount + changeSize];
        int carrySize;
        if (changeSize > 0) {
            carrySize = currentIssueCount;
        } else {
            carrySize = currentIssueCount + changeSize;
        }
        for (int i = 0; i < carrySize; i++) {
            assignedIssues[i] = temp[i];
        }
        delete[] temp;
        currentIssueCount += changeSize;
    } else {
        if (assignedIssues != nullptr)
            delete[] assignedIssues; 
        currentIssueCount = 0;
        assignedIssues = nullptr;
    }
}

void Employee::addIssue(Issue issue) {
    deployIssueArray(1);
    assignedIssues[currentIssueCount - 1] = issue;
}
            
bool Employee::removeIssue (int id) {
    if (currentIssueCount > 0) {
        int removeIndex = -1;
        Issue removedIssue;
        for (int i = 0; i < currentIssueCount; i++) {
            if (assignedIssues[i].getID() == id) { 
                removeIndex = i; removedIssue = assignedIssues[i]; 
            }
        }
        if (removeIndex > -1) {
            for (int i = removeIndex; i < currentIssueCount - 1; i++) {
                assignedIssues[i] = assignedIssues[i+1];
            }
            deployIssueArray(-1);
            return true;
        }
    }
    return false;
}

 Issue* Employee::findIssue(const int id) const {
    for (int i = 0; i < currentIssueCount; i++) {
        if (assignedIssues[i].getID() == id) {
            return assignedIssues + i;
        }
    }
    return nullptr;
}

void Employee::transferIssuesTo(Employee* newAssignee) {
    if (currentIssueCount > 0) {
        int carryAmount = currentIssueCount;
        newAssignee->deployIssueArray(currentIssueCount);
        for (int i = 0; i < carryAmount; i++) {
            newAssignee->assignedIssues[newAssignee->currentIssueCount - carryAmount + i] = assignedIssues[i];
        }
        deployIssueArray(-currentIssueCount);
    }
}

string Employee::details () const {
    return name + ", " + title + ", " + to_string(currentIssueCount) + " issue(s).";
}

string Employee::issueDetails () const {
    string result = "";
    for (int i = 0; i < currentIssueCount; i++) {
        result += assignedIssues[i].details(name);
    }
    return result;
}

int Employee::getIssueCount() const {
    return currentIssueCount;
}
