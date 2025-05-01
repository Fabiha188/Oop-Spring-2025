#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    fstream file;
    file.open("data_records.txt",ios::out);
    if(!file.is_open()){
        cerr<<"File cant Open\n";
return 1;}
    
    file<<"Record 1\n";
    file<<"Record 2\n";
    file<<"Record 3\n";
    file<<"Record 4\n";
    file.close();
    

fstream ifile;
ifile.open("data_records.txt",ios::in);
if(!ifile.is_open()){
    cerr<<"File cant Open\n";
    return 1;}
ifile.seekg(20,ios::beg);//20 ki jaga 18 hona chahiye but already \r hai so usy count krny ki wajah se 20 hogye
string data;
cout<<"Reading Third Line From File\n";
getline(ifile,data);
cout<<data<<endl;
ifile.close();
}
