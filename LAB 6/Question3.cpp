#include <iostream>
#include <string>
using namespace std;
class Person{
    protected:
    string name;
    int age;
    public:
    Person(string n,int a):name(n),age(a){}
    void display(){
        cout<<"Details\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};
class Teacher:public Person{
    protected:
    string subject;
    public:
    Teacher(string n,int a,string s):Person(n,a),subject(s){}    void display(){
        Person::display();
        cout<<"Subject of Teaching: "<<subject;
    }
};
class Researcher:public Person{
    protected:
    string researchArea;
    public:
    Researcher(string n,int a,string r):Person(n,a),researchArea(r){}
    void display(){
        
        cout<<"Research Area: "<<researchArea;
    }
};
class Professor:public Teacher,public Researcher{
    protected:
    int publication;
    public:
    Professor(string n,int a,string s,string r,int p):Teacher(n,a,s),Researcher(n,a,r),publication(p){}
    void display(){
        Teacher::display();
        Researcher::display();
        cout<<"\nNum Of Publication "<<publication<<endl;
    }
};

int main() {
    Professor p1("John",35,"Physcology","Deja Vu",6);
    p1.display();
}
