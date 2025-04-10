#include <iostream>
using namespace std;

class Person {
protected:
    string name, contactNumber, address;
    int age;

public:
    Person(string n, int a, string contact, string addr = "")
        : name(n), age(a), contactNumber(contact), address(addr) {}

    virtual void displayInfo() const {
        cout << "Name: " << name << "\nAge: " << age << "\nContact: " << contactNumber;
        if (!address.empty()) cout << "\nAddress: " << address;
        cout << "\n";
    }

    virtual void updateInfo(string newContact, string newAddress = "", double newSalary = 0) {
        contactNumber = newContact;
        if (!newAddress.empty()) address = newAddress;
    }

    virtual ~Person() {}
};

class Patient : public Person {
    string patientID, medicalHistory, doctorAssigned;

public:
    Patient(string n, int a, string contact, string id, string history, string doctor)
        : Person(n, a, contact), patientID(id), medicalHistory(history), doctorAssigned(doctor) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Patient ID: " << patientID << "\nMedical History: " << medicalHistory
             << "\nDoctor Assigned: " << doctorAssigned << "\n";
    }
};

class Doctor : public Person {
    string specialization;
    double consultationFee;
    string patientsList;

public:
    Doctor(string n, int a, string contact, string spec, double fee, string patients)
        : Person(n, a, contact), specialization(spec), consultationFee(fee), patientsList(patients) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Specialization: " << specialization << "\nConsultation Fee: $" << consultationFee
             << "\nPatients List: " << patientsList << "\n";
    }
};

class Nurse : public Person {
    string assignedWard, shiftTimings;

public:
    Nurse(string n, int a, string contact, string ward, string shift)
        : Person(n, a, contact), assignedWard(ward), shiftTimings(shift) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Assigned Ward: " << assignedWard << "\nShift Timings: " << shiftTimings << "\n";
    }
};

class Administrator : public Person {
    string department;
    double salary;

public:
    Administrator(string n, int a, string contact, string dept, double sal)
        : Person(n, a, contact), department(dept), salary(sal) {}

    void updateInfo(string newContact, string newAddress = "", double newSalary = 0) override {
        Person::updateInfo(newContact, newAddress);
        if (newSalary > 0) salary = newSalary;
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\n";
    }
};

int main() {
    Person* p1 = new Patient("Azlan", 30, "123456789", "P001", "Diabetes", "Dr. Smith");
    Person* p2 = new Doctor("Dr. Yahya", 45, "987654321", "Cardiology", 150.00, "Rafay, Bob");
    Person* p3 = new Nurse("Aqsa", 28, "555888777", "ICU", "Night");
    Person* p4 = new Administrator("Mr. Hadi", 50, "111222333", "HR", 60000);

    cout << "\n--- Hospital Staff & Patients ---\n";
    p1->displayInfo();
    cout << "\n";
    p2->displayInfo();
    cout << "\n";
    p3->displayInfo();
    cout << "\n";
    p4->displayInfo();

    cout << "\n--- Updating Administrator Contact & Salary ---\n";
    p4->updateInfo("89347031", "New Office Address", 65000);
    p4->displayInfo();

    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
