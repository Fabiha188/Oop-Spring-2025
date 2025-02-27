#include <iostream>
#include <string>
using namespace std;
class employees{
    string name,designation;
    public:
    employees(string n,string d):name(n),designation(d){}
    void display(){
        cout<<"Name "<<name<<endl;
        cout<<"Designation "<<designation<<endl;
    }
    };
class projects{
    string title,deadline;
    employees* employee[10];
    int count=0;
    public:
    projects(string t,string d):title(t),deadline(d){}
    void addEmployees(employees *e){
        employee[count++]=e;
    }
    void display()const{
        cout<<"Project's Details\n";
        cout<<"Tile: "<<title<<endl;
        cout<<"Deadline: "<<deadline<<endl;
        cout<<"Employees Association in "<<title<<endl;
        for(int i=0;i<count;i++){
            employee[i]->display();
        }
    }
};
int main(){
    employees e1("John Elice","Digital Marketer");
    e1.display();
    projects p1("Campaign Management","24-Dec-2025");
    p1.addEmployees(&e1);
    cout<<endl;
    p1.display();
     projects p2("Graphic Designing","24-March-2025");
    p2.addEmployees(&e1);
    cout<<endl;
    p2.display();
}
