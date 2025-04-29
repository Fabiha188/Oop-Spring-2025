#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
	ifstream file("vehicles.txt");
	if(!file){
		cerr<<"Cannot open the file";
		return 1;
}

cout<<"Reading data from the file\n";
string data;
while (getline(file,data)){
	cout<<data<<endl;
}
file.close();
return 0;
}
