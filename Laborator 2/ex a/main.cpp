#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

class Soft {
private:
    char* numeFisier;
    char* extensie;
    time_t dataCreare;
public:
    // Constructorul cu parametri
    Soft( char* nume,  char* extensie) {
        this->numeFisier = new char[strlen(nume) + 1];
        strcpy(this->numeFisier, nume);

        this->extensie = new char[strlen(extensie) + 1];
        strcpy(this->extensie, extensie);

        this->dataCreare = time(0); // Se initializeaza cu timpul curent
    }

    // Destructor
    ~Soft() {
        delete[] numeFisier;
        delete[] extensie;
    }

    // Constructorul de copiere
    Soft( Soft& soft) {
        this->numeFisier = new char[strlen(soft.numeFisier) + 1];
        strcpy(this->numeFisier, soft.numeFisier);

        this->extensie = new char[strlen(soft.extensie) + 1];
        strcpy(this->extensie, soft.extensie);

        this->dataCreare = soft.dataCreare;
    }

    // Constructorul de schimbare a tipului
    Soft( char* numeFisier) {
        this->numeFisier = new char[strlen(numeFisier) + 1];
        strcpy(this->numeFisier, numeFisier);

        this->extensie = new char[4]; // Se presupune ca extensia are 3 caractere ultim 0
        strcpy(this->extensie, "txt"); // Se initializeaza cu txt

        this->dataCreare = time(0); // Se initializeaza cu timp curent
    }

    // Functia de redenumire a fisierului
    void redenumire( char* numeNou) {
        delete[] this->numeFisier;
        this->numeFisier = new char[strlen(numeNou) + 1];
        strcpy(this->numeFisier, numeNou);
    }

    // Functia de transfer in alt directoriu (presupunere ca directorul este reprezentat prin numeDirector)
    void transfer( char* numeDirector) {
        // Se presupune ca se realizeaza acesr transfer
        cout <<"\nFisierul " << this->numeFisier << " a fost transferat in directorul " << numeDirector << "." << endl;
    }

    // Functia de modificare a extensiei
    void modificareExtensie( char* extensieNoua) {
        delete[] this->extensie;
        this->extensie = new char[strlen(extensieNoua) + 1];
        strcpy(this->extensie, extensieNoua);
    }

    // Functia pentru afisarea informatiilor despre soft
    void afisareInformatii()  {
        cout << "\nNume fisier: " << this->numeFisier << endl;
        cout << "Extensie: " << this->extensie << endl;
        cout << "Data creare: " << ctime(&this->dataCreare);
    }
};

int main() {
    Soft
    soft1("document1", "doc");
    soft1.afisareInformatii();

    soft1.redenumire("nouDocument");
    soft1.modificareExtensie("txt");

    soft1.afisareInformatii();

    soft1.transfer("altDirector");

    return 0;
}
