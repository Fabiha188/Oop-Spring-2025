#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    ifstream file("large_log.txt",ios::in);
    if(!file.is_open()){
        cerr<<"File Cannot Open\n";
        return 1;
    }
    char data[11]={};
    file.read(data,10);
    data[file.gcount()] = '\0';
    cout<<data<<endl;
    cout<<"Current position of pointer "<<file.tellg()<<endl;
    file.read(data,10);
    data[file.gcount()] = '\0';
    cout<<data<<endl;
    cout<<"Current position of pointer "<<file.tellg();
file.close();
}
