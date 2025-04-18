#include <iostream>
using namespace std;
class MenuItem{
    protected:
    string dishName;
    double price;
    public:
    MenuItem(string n,double p):dishName(n),price(p){
    }
    virtual void showDetails()=0;
    virtual void prepare()=0;
    
    
    virtual ~MenuItem() {}
    };
class Apetizer:public MenuItem{
    
    public:
    Apetizer(string n,double p):MenuItem(n,p){}
    void showDetails(){
        cout<<"=======Apetizer Details========\n";
        cout<<"Dish Name: "<<dishName<<endl;
        cout<<"Price: "<<price<<endl;
        
    }
    void prepare(){
        cout << "Preparation Steps for " << dishName << ":\n";
        cout << "1. Preheat the fryer to 180°C.\n";
        cout << "2. Slice and season vegetables.\n";
        cout << "3. Coat with batter and deep fry until golden brown.\n";
        cout << "4. Drain excess oil and plate with a dipping sauce.\n";
    }
    
};
class MainCourse:public MenuItem{
    
    public:
    MainCourse(string n,double p):MenuItem(n,p){}
    void showDetails(){
        cout<<"=======MainCourse Details========\n";
        cout<<"Dish Name: "<<dishName<<endl;
        cout<<"Price: "<<price<<endl;
        
    }
    void prepare(){
       cout << "Preparation Steps for " << dishName << ":\n";
        cout << "1. Marinate meat in spices and yogurt for 2 hours.\n";
        cout << "2. Heat oil in a deep pan and sauté onions.\n";
        cout << "3. Add marinated meat and cook on medium heat.\n";
        cout << "4. Simmer until meat is tender and sauce thickens.\n";
        cout << "5. Garnish with coriander and serve hot with rice or bread.\n";
    }
    
};
int main(){
    MenuItem* apetizer=new Apetizer("Crispy Veg Pakora",2000);
    MenuItem* mainmenu=new MainCourse("Pizza",3500);
    apetizer->showDetails();
    apetizer->prepare();
    mainmenu->showDetails();
    mainmenu->prepare();
    delete apetizer;
    delete mainmenu;
}
