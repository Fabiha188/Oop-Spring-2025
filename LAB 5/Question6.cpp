#include <iostream>
#include <string>
using namespace std;
class Levels{
    string mode;
    float duration;
    public:
    Levels(string m,float d):mode(m),duration(d){}
    void display(){
        cout<<"Level Mode: "<<mode<<endl;
        cout<<"Level Duration: "<<duration<<endl;
    }
};
class VideoGame{
    string title,genre;
    Levels l1,l2;
    public:
    VideoGame(string t,string g,string m1,float d1,string m2,float d2):title(t),genre(g),l1(m1,d1),l2(m2,d2){}
    void display(){
        cout<<"Game Details"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Genre: "<<genre<<endl;
        cout<<"level 1 Details:"<<endl;
        l1.display();
        cout<<"level 2 Details:"<<endl;
        l2.display();
    }
};

int main() {
    VideoGame g1("Candy Crush","match three","Basic",2.5,"Hard",10);
    g1.display();

    return 0;
}
