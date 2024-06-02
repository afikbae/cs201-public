/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#ifndef EMPLOYEE_
#define EMPLOYEE_
#include <string>
#include "Issue.h"
using namespace std;
class Employee {
    public:
        Employee();
        Employee(string, string);
        ~Employee();
        Employee& operator=(Employee&);
        
        void addIssue(Issue);
        bool removeIssue(int id);
        void transferIssuesTo (Employee* newAsignee);
        Issue* findIssue(const int id) const;

        string getName() const;
        int getIssueCount() const;
        string details() const;
        string issueDetails() const;
    private:
        string name;   // unique name
        string title;
        Issue* assignedIssues;
        int currentIssueCount;

        void deployIssueArray (int changeSize);
};

#endif
