#include <iostream>
#include <string>
using namespace std;
class Student{
  string ID;
  float* score;
  
  string name;
  
  public:
  Student(string i,string n,float s1[]){
      ID=i;
      name=n;
      score=new float[3];
      for(int i=0;i<3;i++){
          score[i]=s1[i];
      }
  }
  Student(const Student &S1){
      ID = S1.ID;
      name = S1.name;
      score=new float[3];
      for(int i=0;i<3;i++){
          score[i]=S1.score[i];
      }
  }
  void display(){
      cout<<"ID "<<ID<<endl;
      cout<<"Student's Name "<<name<<endl;
      for(int i=0;i<3;i++){
         cout<<"score "<<i+1<<": "<<score[i]<<endl; 
      }
  }
  ~Student(){
           delete[] score;
  }
};
int main() {
    float scores[]={76.08,78.92,37.13};
    Student S1("K241022","FABIHA SIDDIQUI",scores);
    S1.display();
    Student S2(S1);
    cout<<endl;
    S2.display();
    return 0;
}
