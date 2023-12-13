#include <iostream>
#include <string>

using namespace std;

// Clasa de baza Vehicul
class Vehicul {
public:
    Vehicul(const string& marca, int anFabricatie)
        : marca(marca), anFabricatie(anFabricatie) {}

    void AfiseazaDetalii() const {
        cout << "Marca: " << marca << ", An de fabricatie: " << anFabricatie << endl;
    }

private:
    string marca;
    int anFabricatie;
};

// Clasa de baza Camion
class Camion {
public:
    Camion(int capacitateTonaj)
        : capacitateTonaj(capacitateTonaj) {}

    void AfiseazaDetaliiCamion() const {
        cout << "Capacitate Tonaj: " << capacitateTonaj << " tone" << endl;
    }

private:
    int capacitateTonaj;
};

// Clasa derivata MasinaDeTeren care mosteneste din Vehicul si Camion
class MasinaDeTeren : public Vehicul, public Camion {
public:
    MasinaDeTeren(const string& marca, int anFabricatie, int capacitateTonaj)
        : Vehicul(marca, anFabricatie), Camion(capacitateTonaj) {}
};

int main() {
    MasinaDeTeren masina("Toyota", 2022, 5);
    masina.AfiseazaDetalii(); // Afiseaza detalii vehicul
    masina.AfiseazaDetaliiCamion(); // Afiseaza detalii camion

    return 0;
}
