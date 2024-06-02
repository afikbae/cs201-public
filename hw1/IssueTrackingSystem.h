/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#ifndef ISSUE_TRACKING_SYSTEM
#define ISSUE_TRACKING_SYSTEM
#include <string>
#include "Employee.h"
using namespace std;

class IssueTrackingSystem {
    public:
        IssueTrackingSystem();
        ~IssueTrackingSystem();
        void addEmployee( const string name, const string title );
        void removeEmployee( const string name );
        void addIssue( const int issueId, const string description, const string assigneeName );
        void removeIssue( const int issueId );
        void changeAssignee( const string previousAssignee, const string newAssignee );
        void showAllEmployees() const;
        void showAllIssues() const;
        void showEmployee( const string name ) const;
        void showIssue( const int issueId ) const;
    private:
        Employee* findEmployee(const string name) const;
        Employee* employees;
        int currentEmps;
        void deployEmployeeArray(int changeSize);
};
#endif
