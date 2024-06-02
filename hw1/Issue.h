/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#ifndef ISSUE_
#define ISSUE_
#include <string>
using namespace std;

class Issue {
    public:
        Issue();
        Issue(int, string);
        string details(string);
        int getID();
        string getDesc();
    private:
        int id; // unique id
        string desc;
};

#endif
