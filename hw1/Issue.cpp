/*
*   @author Mehmet Akif Şahin
*   @author_id 22203673
*   @section CS-201-003
*   @date 19-10-2023
*/

#include "Issue.h"
#include <string>
using namespace std;

Issue::Issue() {
    id = 0;
    desc = "";
}

Issue::Issue (int id, string desc) {
    this->id = id;
    this->desc = desc;
}

int Issue::getID () {
    return this->id;
}

string Issue::getDesc () {
    return this->desc;
}

string Issue::details (string assigneeName) {
    return to_string(id) + ", " + desc + ", " + assigneeName + ".\n";
}
