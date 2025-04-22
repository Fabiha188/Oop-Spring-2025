#pragma once
#include "Course.h"
class LabCourse:public Course{
    double labAssignments;
    double projectWork;
    public:
    LabCourse(string cc, int c, double lA, double pw);
     double calculateGrade();
     void displayInfo();   
};
