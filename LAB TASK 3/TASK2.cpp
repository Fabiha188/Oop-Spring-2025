#include <iostream>
#include <string>
using namespace std;

class Fitness{
string name;
int steps;
int goal;

float coloriesburned;
public:
Fitness(string n,int g){
name=n;
goal=g;
steps=0;
coloriesburned=0;
}
void logsteps(int s){
if(s>0){
steps+=s;
coloriesburned+=s*0.04;
cout<<"current steps you took: "<<steps<<" colories burned "<<coloriesburned<<endl;
}
else{
cout<<"invalid steps \n";
}
}
void checkgoal(){
if(steps>=goal){
cout<<"Congratulations! You've met your daily step goal. \n";
}
else {
cout<< "Keep going! You need " << (goal - steps) << " more steps to reach your goal." <<

endl;
}
}
void display(){
cout<<".................................................................\n";
cout<<"fitness goal for "<<name<<": "<<endl;
cout<<"steps taken: "<<steps<<endl;
cout<<"calories burned: "<<coloriesburned<<endl;
checkgoal();
cout<<"............................end.....................................\n";

}

};
int main(){
Fitness A("ALISHBA", 10000);
A.logsteps(100);
A.display();
A.logsteps(4000);
A.display();
A.logsteps(7000);
A.display();
}
