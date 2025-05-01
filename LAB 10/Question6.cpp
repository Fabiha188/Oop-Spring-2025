#include<iostream>
#include <fstream>
#include <cstring>
using namespace std;
class InvetarySystem{
    int id;
    char name[20];
    public:
    InvetarySystem(){
        id=0;
        strcpy(name,"");
    }
    InvetarySystem(int i,char* n){
        id=i;
        strncpy(name,n,sizeof(name)-1);
        name[sizeof(name)-1]='\0';    
    }
    void writeData(string fileName){
        ofstream ofile;

        ofile.open(fileName,ios::binary);
        if(!ofile.is_open()){
            cerr<<"can't open the file\n";
            return ;
        }
        ofile.write((char*)this, sizeof(*this));
        ofile.close();

    }
    void readData(string fileName){
        ifstream ifile;
        ifile.open(fileName, ios::binary);
        if(!ifile.is_open()){
            cerr<<"NO such File Found\n";
            return;
        }
        ifile.read((char*)this,sizeof(*this));
        ifile.close();
    }
    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
    }
};
int main() {
    
    InvetarySystem item1(101, (char*)"Monitor");
    cout << "Writing Data to File..." << endl;
    item1.writeData("inventory.dat");

    
    InvetarySystem item2;
    cout << "Reading Data from File..." << endl;
    item2.readData("inventory.dat");

   
    cout << "Displaying Read Data:" << endl;
    item2.display();

    return 0;
} 
