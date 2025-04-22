#include <iostream>
#include "LabCourse.h"
#include "Course.h"
using namespace std;

LabCourse:: LabCourse(string cc,int c, double lA, double pw): Course(cc, c), labAssignments(lA), projectWork(pw){}

double LabCourse::calculateGrade()
{
    return  labAssignments* 0.5 + projectWork * 0.5;
}
void LabCourse::displayInfo()
{
    cout << "=====Lab Course Deatials======\n";
    cout << "Course Code: " << courseCode << endl;
    cout << "Credit Hour: " << credits << endl;
    cout << "Lab Assignments: " << labAssignments << endl;
    cout << "ProjectWork: " << projectWork << endl;
    cout << "Grade: " << calculateGrade();
}
