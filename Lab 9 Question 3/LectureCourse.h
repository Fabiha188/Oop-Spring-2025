#pragma once
#include <iostream>
#include "Course.h"
using namespace std;
class LectureCourse:public Course{
    
    double midTermMarks,finalExamMarks;
    public:
     LectureCourse(string cc,int c,double m,double f);
     double calculateGrade();
     void displayInfo();
    
};

   
