
#include <iostream>
#include <string>
using namespace std;
class Account{
    protected:
    int accountNumber;
    float balance;
    public:
    Account(int a,float b):accountNumber(a),balance(b){}
    void display(){
        cout<<"Account Number: "<< accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
};
class SavingAccount:public Account{
    protected:
    float interestRate;
    public:
    SavingAccount(int a,float b,float i):Account(a,b),interestRate(i){}
    void display(){
        Account::display();
        cout<<"Interest Rate: "<<interestRate<<endl;
    }
};
class CheckingAccount:public Account{
    protected:
    float overdraftLimit;
    public:
    CheckingAccount(int a,float b,float o):Account(a,b),overdraftLimit(o){}
    void display(){
        Account::display();
        cout<<"Over Draft Limit: "<<overdraftLimit<<endl;
    } 
};
int main() {
    int a1,a2;
    float b1,b2,i,o;
    cout<<"Enter the Details for Saving Account: "<<endl;
    cout<<"Account Number: ";
    cin>>a1;
    cout<<"Balance: ";
    cin>>b1;
    cout<<"Interest Rate: ";
    cin>>i;
    cout<<"Enter the Details for Checking Account: "<<endl;
    cout<<"Account Number: ";
    cin>>a2;
    cout<<"Balance: ";
    cin>>b2;
    cout<<"Over Draft Limit: ";
    cin>>o;
    SavingAccount s1(a1,b1,i);
    s1.display();
    CheckingAccount c1(a2,b2,o);
    c1.display();

    return 0;
}
