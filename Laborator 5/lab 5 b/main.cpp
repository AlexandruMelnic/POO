#include <iostream>
#include <string>

using namespace std;

class Automobil {
public:
    Automobil(const string& marca) : marca(marca) {}

    virtual void afisare() const {
        cout << "Marca: " << marca << endl;
    }

private:
    string marca;
};

class Vehicul : public Automobil {
public:
    Vehicul(const string& marca, int capacitate) : Automobil(marca), capacitate(capacitate) {}

    void afisare() const override {
        Automobil::afisare();
        cout << "Capacitate: " << capacitate << " persoane" << endl;
    }

private:
    int capacitate;
};

class Camion : public Automobil {
public:
    Camion(const string& marca, int tonaj) : Automobil(marca), tonaj(tonaj) {}

    void afisare() const override {
        Automobil::afisare();
        cout << "Tonaj: " << tonaj << " tone" << endl;
    }

private:
    int tonaj;
};

class MasinaDeTeren : public Vehicul, public Camion {
public:
    MasinaDeTeren(const string& marca, int capacitate, int tonaj)
        : Vehicul(marca, capacitate), Camion(marca, tonaj) {}

    void afisare() const override {
        Vehicul::afisare();
        Camion::afisare();
    }
};

int main() {
    MasinaDeTeren masina("Toyota", 5, 2);
    masina.afisare();

    return 0;
}
