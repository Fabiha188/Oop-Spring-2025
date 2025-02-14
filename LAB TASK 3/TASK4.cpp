#include <iostream>
#include <string>
using namespace std;
class Car{
string brand;
string model;
float fuelcapacity;
float current;
float consumption;// liters per km

public:
Car(string b,string m,float cap,float con){
brand=b;
model=m;
fuelcapacity=cap;

y
consumption=con;
current=cap;
}
void check(){
if(current<=0.1*fuelcapacity){
cout<<"the fuel level is low.please refuel soon\n";
}
}
void destination(float distance){
float need=distance*consumption;
if(need>current){
cout<<"not enough fuel for destination \n";
return;
}
else{
current-=need;
cout<<"you covered your destination distance "<<distance<<" km. Remaining fuel: "<<

current << " liters." << endl;
check();
}
}
void refuel(float amount){
if(amount<=0){
cout<<"insufficient amount\n";

}
else if(current+amount>fuelcapacity){
current=fuelcapacity;
cout<<"tank is full\n";}
else{
current+=amount;
cout<<"the amount is added.current fuel status is "<<current<<endl;
}
}

void display(){
cout<<"\n....................DETAILS....................\n";
cout<<"car: "<<brand<<endl;
cout<<"model: "<<model<<endl;
cout<<"fuel capacity: "<<fuelcapacity<<endl;
cout<<"current fuel: "<<current<<endl;
cout<<"fuel consumption: "<<consumption<<endl<<endl;
}
};
int main(){
Car mycar("Honda","Civic",50,0.06);
mycar.display();
mycar.destination(400);
mycar.refuel(12);
mycar.destination(250);
return 0;
}
