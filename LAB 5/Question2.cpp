#include <iostream>
#include <string>
using namespace std;
class scores{
    float score[3];
    public:
    scores(float s[]){
        for(int i=0;i<3;i++){
            score[i]=s[i];
        }
    }
    scores(const scores& s){
        for(int i=0;i<3;i++){
            score[i]=s.score[i];
        }
    }
    void display(){
        for(int i=0;i<3;i++){
            cout<<"score "<<i+1<<": "<<score[i]<<endl;
        }
    }
};
class Student{
  string ID;
  scores score;
  string name;
  
  public:
  Student(string i, string n, float s1[]) : ID(i), name(n), score(s1) {}

  Student(const Student &S1) : ID(S1.ID), name(S1.name), score(S1.score) {}

  void display(){
      cout<<"ID "<<ID<<endl;
      cout<<"Student's Name "<<name<<endl;
      score.display();
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
