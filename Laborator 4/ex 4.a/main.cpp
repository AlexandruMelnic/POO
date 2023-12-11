#include <iostream>
#include <string>

using namespace std;

class Transport {
private:
    string marca;

public:

    int abc;
    // Constructor
    Transport(const string &marca) : marca(marca) {}

    // Constructor de copiere
    Transport(const Transport &other) : marca(other.marca) {}

    // Operator de atribuire
    Transport& operator=(const Transport& other) {
        if (this != &other) {
            marca = other.marca;
        }
        return *this;//Returnăm o referință la obiectul curent
    }

    // Funcție pentru afișare
    void afisare() const {
        cout << "Marca: " << marca << endl;
    }

    // Funcție pentru citire
    void citire() {
        cout << "Introduceti marca: ";
        cin >> marca;
    }
    // Destructor
    ~Transport() {}
};

class TransportAerian : public Transport {
private:
    int altitudine;

public:
    // Constructor
    TransportAerian(const string &marca, int altitudine) : Transport(marca), altitudine(altitudine) {}

    // Constructor de copiere
    TransportAerian(const TransportAerian& other) : Transport(other), altitudine(other.altitudine) {}

    // Operator de atribuire
    TransportAerian &operator=(const TransportAerian& other) {
    if (this != &other) {
        operator=(other);
        altitudine = other.altitudine;
    }
    return *this;
}

    // Funcție pentru afișare
    void afisare() const {
        Transport::afisare();
        cout << "Altitudine maxima: " << altitudine << " metri" << endl;
    }

    // Funcție pentru citire
    void citire() {
        Transport::citire();
        cout << "Introduceti altitudinea maxima: ";
        cin >> altitudine;
    }

    // Destructor
    ~TransportAerian() {}
};

class Elicopter : TransportAerian {
private:
    int numarlocuri;

public:
    // Constructor
Elicopter(const string &marca, int altitudine, int numarlocuri) : TransportAerian(marca, altitudine), numarlocuri(numarlocuri) {
    cout << "Elicopter creat\n";
}
    // Constructor de copiere
    Elicopter(const Elicopter &other) : TransportAerian(other), numarlocuri(other.numarlocuri) {}

    // Operator de atribuire
    Elicopter &operator=(const Elicopter &other) {
        if (this != &other)
            this->abc;
            TransportAerian::operator=(other);
            numarlocuri = other.numarlocuri;
        }
        return *this;
    }

    // Funcție pentru afișare
    void afisare() const {
        TransportAerian::afisare();
        cout << "Numar locuri: " << numarlocuri << endl;
    }

    // Funcție pentru citire
    void citire() {
        TransportAerian::citire();
        cout << "Introduceti numarul de locuri: ";
        cin >> numarlocuri;
    }

    // Destructor
    ~Elicopter() {}
};

int main() {
    // 50 de obiecte de tip Elicopter intr-un rand de cod si sa demonstrezi ca obiectete se creeaza
    for(int i = 0; i < 50; i++) {
            Elicopter elicopter("", 0, 0);
    }


    // Creare obiect elicopter
    Elicopter elicopter("Elicopter1", 1000, 4);

    // Afișare informații despre elicopter
    cout << "Informatii despre elicopter:" << endl;
    elicopter.afisare();
    cout << endl;

    // Creare copie elicopternjj'
    Elicopter copieElicopter = elicopter;
    cout << "Informatii despre copia elicopterului:" << endl;
    copieElicopter.afisare();
    cout << endl;

    // Creare alt elicopter și citire informații
    Elicopter altElicopter("A", 1, 3);
    cout << "Introduceti informatii despre alt elicopter:" << endl;
    altElicopter.citire();
    cout << endl;
    // Afișare informații despre alt elicopter
    cout << "Informatii despre alt elicopter:" << endl;
    altElicopter.afisare();

    return 0;
}



