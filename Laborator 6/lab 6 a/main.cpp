#include <iostream>

using namespace std;

class InstitutieDeInvatamant {
public:
    virtual void descriere() = 0;
    virtual void saySomething() {
        cout << "Something" << endl;
    }
};

class InstitutieDeInvatamantPrescolar : public InstitutieDeInvatamant {
public:
    void descriere() override {
        cout << "Institutie de invatamant prescolar" << endl;
    }
};

class InstitutieDeInvatamantMediu : public InstitutieDeInvatamant {
public:
    void descriere() override {
        cout << "Institutie de invatamant mediu" << endl;
    }
};

class InstitutieDeInvatamantSuperior : public InstitutieDeInvatamant {
public:
    void descriere() override {
        cout << "Institutie de invatamant superior" << endl;
    }
};

int main() {

    InstitutieDeInvatamant * ex1; // e ok
    InstitutieDeInvatamant ex2; // nu e ok
    InstitutieDeInvatamant & ex3; // smart pointer

    InstitutieDeInvatamant *institutii[] = {
        new InstitutieDeInvatamantPrescolar(),
        new InstitutieDeInvatamantMediu(),
        new InstitutieDeInvatamantSuperior()
};

    // Student *s1 = new Student;

    // InstitutieDeInvatamant *institutii[100]; // compilatorul nu cunoaste din cate elemente va fi format tabloul

    for (int i = 0; i < 3; i++) {
        institutii[i]->descriere();
        institutii[i]->saySomething();
    }

    for (int i = 0; i < 3; i++) {
        delete institutii[i];
}


    InstitutieDeInvatamantPrescolar * t1; // Citi constructori in total vor fi apelati aici ?    2     0
    InstitutieDeInvatamantPrescolar t2; // Citi constructori in total vor fi apelati aici ?   2        2
    InstitutieDeInvatamantPrescolar t3[10]; // Citi constructori in total vor fi apelati aici ?   2     20

    InstitutieDeInvatamant t4; // se va compila oare ?  nu      corect
    InstitutieDeInvatamant t5 = t2; // se va compila oare ?  nu    corect


    return 0;
}
