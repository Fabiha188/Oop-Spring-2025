#include <iostream>
#include <string>
using namespace std;
class Vehicle{
    protected:
    string brand;
    int speed;
    Vehicle(string b,int s):brand(b),speed(s){}
    void display(){
        cout<<"car's Details\n";
        cout<<"Brand: "<<brand<<endl;
        cout<<"Speed: "<<speed<<endl;
    }
};
class Car:public Vehicle{
    protected:
    int seats;
    Car(string b,int s,int seat):Vehicle(b,s),seats(seat){}
    void display(){
        Vehicle::display();
        cout<<"seats: "<<seats<<endl;
    }
};
class ElectricCar:public Car{
    protected:
    int batteryLife;
    public:
    ElectricCar(string b,int s,int seat,int bl):Car(b,s,seat),batteryLife(bl){}
    void display(){
        cout<<"Car's Details\n";
        Car::display();
        cout<<"Battery Life: "<<batteryLife;
    }
};
int main() {
    ElectricCar E1("Honda",180,5,4);
    E1.display();
    return 0;
}
