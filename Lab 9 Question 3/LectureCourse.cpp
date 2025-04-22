#include "LectureCourse.h"
#include "Course.h"
LectureCourse ::LectureCourse(string cc, int c, double m, double f) : Course(cc, c), midTermMarks(m), finalExamMarks(f) {}
double LectureCourse ::calculateGrade()
{
    return midTermMarks * 0.4 + finalExamMarks * 0.6;
}
void LectureCourse::displayInfo()
{
    cout << "=====Lecture Course Deatials======\n";
    cout << "Course Code: " << courseCode << endl;
    cout << "Credit Hour: " << credits << endl;
    cout << "Mid Term Marks: " << midTermMarks << endl;
    cout << "Final Exam Marks: " << finalExamMarks << endl;
    cout << "GraSde: " << calculateGrade();
}
