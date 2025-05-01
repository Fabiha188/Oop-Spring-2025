#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    fstream file;
    file.open("config.txt",ios::out);
    if(!file.is_open()){
        cout<<"Cannot open the file\n";
        return 1;
    }
    file<<"AAAAABBBBBCCCCC\n";
    file.close();
    fstream file2;
    file2.open("config.txt",ios::in);
    if(!file2.is_open()){
        cout<<"Cannot open the file\n";
        return 1;
    }
    cout<<"Reading From File\n";
    char ch;
    while(file2.get(ch)){
        
        cout<<ch;
    }
    file2.close();
    fstream file3;
    file3.open("config.txt",ios::out|ios::in);
    if(!file3.is_open()){
        cout<<"Cannot open the file\n";
        return 1;
    }
    file3.seekp(5,ios::beg);

    file3<<"XXXXX";
    file3.seekg(0);
    while(file3.get(ch)){
        
        cout<<ch;
    }
    file3.close();
}
