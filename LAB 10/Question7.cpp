#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ofstream file;
    file.open("sensor_log.txt",ios::app);
    if(!file.is_open()){
        cout<<"Cannot open the file\n";
    }
    file<<"Sensor 1: 25.5 C\n";
    cout<<"current possition pointer after first line: "<<file.tellp()<<endl;
    file<<"Sensor 2: 98.1%RH\n";
    cout<<"current possition pointer after Second line: "<<file.tellp();
    file.close();

}
