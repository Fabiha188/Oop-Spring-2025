#include<iostream>
using namespace std;
#include <string>
#include "LectureCourse.h"
#include "LabCourse.h"
int main(){
    Course* English=new LabCourse("LbC-3y3",16,28.9,88);
    Course* Oop=new LabCourse("TNK-364",14,48.5,93);
    cout<<"-------------------------------\n";
    English->calculateGrade();
    English->displayInfo();
    cout<<"-------------------------------\n";
    Oop->calculateGrade();
    Oop->displayInfo();

}
