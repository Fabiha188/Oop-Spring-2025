#include <iostream>
#include <string>
using namespace std;
class Owner{
    public:
    string name;
    Owner(string n):name(n){}
    void display(){
        cout<<"Owner's Name: "<<name<<endl;
    }
};
class Apartment{
  string ID;
  string address;
  Owner* owner ;
  
  public:
  Apartment(string i,string a,string n){
      ID=i;
      address=a;
      owner=new Owner(n);
  }
  Apartment(Apartment &A1){
      ID=A1.ID;
      address=A1.address;
      owner=A1.owner;
  }
  void display(){
      cout<<"ID "<<ID<<endl;
      cout<<"Address "<<address<<endl;
      owner->display();
  }
  ~Apartment(){
      
  }
};
int main() {
    Apartment A1("A209","322 street,NA","Alice Smith");
    A1.display();
    Apartment A2(A1);
    cout<<endl;
    A2.display();
    return 0;
} 
