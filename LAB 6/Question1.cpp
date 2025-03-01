
#include <iostream>
#include <string>
using namespace std;
class Employee{
    protected:
    string name;
    float salary;
    Employee(string n,float s):name(n),salary(s){}
    void display(){
        
        cout<<"Name: "<<name<<endl;
        cout<<"salary: "<<salary<<endl;
    }
};
class Manager:public Employee{
    float bonus;
    public:
    Manager(string n,float s,float b):Employee(n,s),bonus(b){}
    void display(){
        cout<<"Employee Details\n";
        Employee::display();
        cout<<"Bonus: "<<bonus;
    }
};
int main() {
    Manager m1("John Elice",45000,4.6);
    m1.display();

    return 0;
}
