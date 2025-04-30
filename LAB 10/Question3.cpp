#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream file; 
    file.open("vehicles.txt") ;
    if (!file) {
        cerr << "Cannot open the file\n";  
        return 1;
    }

    cout << "Reading data from the file\n";
    string data;
    while (getline(file, data))
    
     { 
        
        if(data.empty()  || data[0]=='#')
        continue;
        istringstream ss(data);
        string type,id,name,stryear,extra,certification;
        getline(ss , type , ',');
        getline(ss , id , ',');
        getline(ss , name , ',');
        getline(ss , stryear , ',');
        getline(ss , extra , ',');
        getline(ss , certification);
        int intyear=stoi(stryear);
        cout<<"Type: "<<type<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"ID: "<<id<<endl;
        cout<<"Year: "<<intyear<<endl;
        cout<<"Extra Data: "<<extra<<endl;
        cout<<"Certification: "<<certification<<endl;
    }

    file.close();  
    return 0;
}
