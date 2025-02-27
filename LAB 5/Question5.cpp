#include <iostream>
#include <string>
using namespace std;

class Doctors {
    string name, specialization, experience;
public:
    Doctors(string n, string s, string e) : name(n), specialization(s), experience(e) {}

    void display() {
        cout << "Doctor's Details\n" << endl;
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Experience: " << experience << endl;
    }
};

class Hospital {
    string name, address;
    Doctors* doctor[10];
    int count = 0;
public:
    Hospital(string n, string a) : name(n), address(a) {}

    void addDoctor(Doctors* d) {
        if (count < 10) {
            doctor[count++] = d;
        } else {
            cout << "Hospital is full, cannot add more doctors.\n";
        }
    }

    void removeDoctor(Doctors* d) {
        for (int i = 0; i < count; i++) {
            if (doctor[i] == d) { 
                for (int j = i; j < count - 1; j++) {
                    doctor[j] = doctor[j + 1];
                }
                count--;
                cout << "Doctor removed from " << name << " Hospital.\n";
                return;
            }
        }
        cout << "Doctor not found in " << name << " Hospital.\n";
    }

    void display() const {
        cout << "Hospital's Details\n";
        cout << "Hospital Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Current Enrolled Doctor's Details " << endl;
        for (int i = 0; i < count; i++) {
            doctor[i]->display();
        }
    }
};

int main() {
    Doctors* d1 = new Doctors("John Elice", "Cardiologist", "15");
    d1->display();
    
    Hospital h1("Jinnah", "Shahrae Faisal");
    h1.addDoctor(d1);
    cout << endl;
    h1.display();

    Doctors* d3 = new Doctors("Dr. Alex Brown", "Dermatologist", "8");  
    Hospital h2("City Hospital", "Gulshan Iqbal");
    h2.addDoctor(d3);  

    Doctors* d2 = new Doctors("Dr. Sarah Williams", "Neurologist", "12");
    h1.removeDoctor(d2);  

    delete d1;
    delete d2;
    delete d3;
}
