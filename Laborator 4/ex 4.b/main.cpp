#include <iostream>
#include <cstring>
using namespace std;

class ElementChimic {
private:
    char denumire[20];
    char proprietatiChimice[100];

public:
    // Constructor implicit
    ElementChimic() {}

    ElementChimic(const char * nume, const char* proprietati) {
        strcpy(denumire, nume);
        strcpy(proprietatiChimice, proprietati);
    }

    void afisareElement() const {
        cout << "Element: " << denumire << "\nProprietati chimice: " << proprietatiChimice << endl;
        cout<<"da";
    }
};

class Medicament {
private:
    char denumire[20];
    ElementChimic elementeChimice[5];
    double cantitati[5];
    int numarElemente;

public:
    Medicament(const char *nume) : numarElemente(0) {
        strcpy(denumire, nume);
    }

    void adaugaElementChimic(const ElementChimic& element, double cantitate) {
        if (numarElemente < 2) {
            elementeChimice[numarElemente] = element;
            cantitati[numarElemente] = cantitate;
            numarElemente++;
        } else {
            cout << "Nu se poate adauga mai multe elemente in medicament." << endl;
        }
    }

    void afisareMedicament() const {
        cout << "Medicament: " << denumire << "\nElemente chimice si cantitati:" << endl;
        for (int i = 0; i < numarElemente; ++i) {
            cout << "  - ";
            elementeChimice[i].afisareElement();
            cout << "     Cantitate: " << cantitati[i] << " mg" << endl;
        }
    }
};

int main() {
    ElementChimic oxigen("Oxigen", "Gas ");
    ElementChimic hidrogen("Hidrogen", "Gas ");

    Medicament aspirina("Aspirina");
    aspirina.adaugaElementChimic(oxigen, 100);
    aspirina.adaugaElementChimic(hidrogen, 50);
    aspirina.afisareMedicament();

    return 0;
}
