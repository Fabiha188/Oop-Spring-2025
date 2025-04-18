#include <iostream>
using namespace std;
class patient{
    protected:
    string name,id;
    public:
    patient(string n,string i):name(n),id(i){
    }
    virtual void displayTreatment()=0;
    virtual double calculateCost()=0;
    virtual ~patient() {}
};
class Inpatient:public patient{
    private:
    int admittedDays;
    double dailyCharges,medicationCost;
    public:
    Inpatient(string n,string i,int a,double d,double m):patient(n,i),admittedDays(a),dailyCharges(d),medicationCost(m){}
    void displayTreatment(){
        cout<<"=======InPatient Details========\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Patient ID: "<<id<<endl;
        cout<<"Admitted Days: "<<admittedDays<<endl;
        cout<<"Daily Charges: "<<dailyCharges<<endl;
        cout<<"Medication Cost: "<<medicationCost<<endl;
    }
    double calculateCost(){
        return (dailyCharges*admittedDays)+medicationCost;
    }
    
};
class Outpatient:public patient{
    private:
    int visits;
    double visitFee,testCost;
    public:
    Outpatient(string n,string i,int v,double vf,double t):patient(n,i),visits(v),visitFee(vf),testCost(t){}
    void displayTreatment(){
        cout<<"=======OutPatient Details========\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Patient ID: "<<id<<endl;
        cout<<"Vists: "<<visits<<endl;
        cout<<"Visit Fee: "<<visitFee<<endl;
        cout<<"Test Cost: "<<testCost<<endl;
    }
    double calculateCost(){
        return (visits*visitFee)+testCost;
    }
};
int main(){
    patient* ip=new Inpatient("Shafay Ahmed","IP234",2,15000,1000);
    patient* op=new Outpatient("Saad Raza","TY874",4,500,4000);
    ip->displayTreatment();
    cout<<"Total Bill Of InPatient "<<ip->calculateCost()<<endl;
    op->displayTreatment();
    cout<<"Total Bill Of OutPatient "<<op->calculateCost();
    delete ip;
    delete op;
}
