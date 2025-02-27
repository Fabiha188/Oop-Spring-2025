#include <iostream>
#include <string>
using namespace std;
class Apartment{
  string ID;
  string address;
  string* name;
  
  public:
  Apartment(string i,string a,string n){
      ID=i;
      address=a;
      name=new string(n);
  }
  Apartment(Apartment &A1){
      this->ID=A1.ID;
      this->address=A1.address;
      name=A1.name;
  }
  void display(){
      cout<<"ID "<<ID<<endl;
      cout<<"Ownner's Name "<<*name<<endl;
      cout<<"Address "<<address<<endl;
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
