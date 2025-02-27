#include <iostream>
#include <string>
using namespace std;
class Alarm{
    string securityLevel;
    public:
    Alarm(string s){
        securityLevel=s;
    }
    void display(){
        cout<<"Alarm's Security Level: "<<securityLevel;
    }
    ~Alarm(){
        cout<<"alarm destructor is  called"<<endl;
    }
};
class House{
    string name,address;
    Alarm alarm;
    public:
    House(string n,string a,string s):name(n),address(a),alarm(s){}
    void display(){
        cout<<"House Deatails\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Adress: "<<address<<endl;
        alarm.display();
    }
    ~House(){
        cout<<"\nHome destructor is called\n";
    }
};
int main(){
    House h1("Siddiqui","N21-Sector 51L","High");
    h1.display();
}
