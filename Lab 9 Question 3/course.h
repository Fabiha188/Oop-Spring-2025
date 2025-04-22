#pragma once
#include <iostream>
#include<string.h>
using namespace std;

class Course{
    protected:
    string courseCode;
    int credits;
    public:
    Course(string cc,int c):courseCode(cc),credits(c){}
    virtual double calculateGrade()=0;
    virtual void displayInfo()=0;
};
