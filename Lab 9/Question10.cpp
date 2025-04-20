#include <iostream>
using namespace std;
class Shipment{
    protected:
    string trackingNumber;
    double weight;
    public:
    Shipment(string t,double w):trackingNumber(t),weight(w){}
    virtual double estimateDeliveryTime()=0;
    virtual void showDetails()=0;
    virtual ~Shipment(){}
};
class AirFreight:public Shipment{
    public:
    AirFreight(string t,double w):Shipment(t,w){}
    double estimateDeliveryTime()override{
        return weight*0.5;
    }
    void showDetails()override{
        cout<<"======Air Freight Details=======\n";
        cout<<"Tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Estimate Delivery Time: "<<estimateDeliveryTime()<<endl;
        
    }
};
class GroundShipment:public Shipment{
    public:
    GroundShipment(string t,double w):Shipment(t,w){}
    double estimateDeliveryTime()override{
        return weight*1.0;
    }
    void showDetails()override{
        cout<<"======Ground Shipment Details=======\n";
        cout<<"Tracking Number: "<<trackingNumber<<endl;
        cout<<"Weight: "<<weight<<endl;
        cout<<"Estimate Delivery Time: "<<estimateDeliveryTime()<<endl;
        
    }
};
int main(){
    Shipment* Air=new AirFreight("AIR123", 20.5);
    Shipment* Ground=new GroundShipment("GRD798", 23.75);
    cout<<"Estimate Delivery Time Of Air: "<<Air->estimateDeliveryTime()<<endl;
    Air->showDetails();
    cout<<"-----------------------\n";
    cout<<"Estimate Delivery Time Of Ground: "<<Ground->estimateDeliveryTime()<<endl;
    Ground->showDetails();
    
}
