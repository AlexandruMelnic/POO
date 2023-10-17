#include <iostream>

using namespace std;

struct Vector {
    double* elements;
    int size;
};

void initializare(Vector &v, int size) {
    v.size = size;
    v.elements = new double[size];
}

void elimina(Vector &v) {
    delete[] v.elements;
}

void resize(Vector  &v, int new_size) {
    double* element_nou = new double[new_size];
    int minSize = (new_size < v.size) ? new_size : v.size;

    for (int i = 0; i < minSize; i++) {
        element_nou[i] = v.elements[i];
    }

    delete[] v.elements;
    v.elements = element_nou;
    v.size = new_size;
}

void extinde(Vector &v, int aditionalSize) {
    int new_size = v.size + aditionalSize;
    resize(v, new_size);
}

double &at(Vector& v, int index) {
    return v.elements[index];
}

double suma_elemente_pare(Vector& v) {
    double sum = 0.0;
    for (int i = 0; i < v.size; i++) {
        if (i % 2 == 0) {
            sum += v.elements[i];
        }
    }
    return sum;
}

void printMenu() {
    cout << "---------------------------------------" << endl;
    cout << "1. Afisare elemente vector" << endl;
    cout << "2. Afisare suma elementelor pare" << endl;
    cout << "3. Adunare un numar la fiecare element" << endl;
    cout << "4. Marire dimensiune vector" << endl;
    cout << "5. Iesire" << endl;
    cout << "---------------------------------------" << endl;
}

int main() {
    int size;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> size;

    Vector vec;
    initializare(vec, size);

    cout << "Introduceti elementele vectorului: ";
    for (int i = 0; i < vec.size; i++) {
        cin >> vec.elements[i];
    }

    int optiune;
    while (true) {
        printMenu();
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch(optiune) {
            case 1:
                cout << "Elementele vectorului: ";
                for (int i = 0; i < vec.size; i++) {
                    cout << vec.elements[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                cout << "Suma elementelor pare: " << suma_elemente_pare(vec) << endl;
                break;
            case 3:
                double numarDeAdunat;
                cout << "Introduceti un numar pentru adunare: ";
                cin >> numarDeAdunat;
                for (int i = 0; i < vec.size; i++) {
                    vec.elements[i] += numarDeAdunat;
                }
                cout << "Vectorul modificat: ";
                for (int i = 0; i < vec.size; i++) {
                    cout << vec.elements[i] << " ";
                }
                cout << endl;
                break;
            case 4:
                char raspuns;
                cout << "Doriti sa mariti vectorul? (Da/Nu): ";
                cin >> raspuns;

                if (raspuns == 'D' || raspuns == 'd') {
                    int aditionalSize;
                        cout << "Introduceti cat doriti sa mariti vectorul: ";
                        cin >> aditionalSize;
                    extinde(vec, aditionalSize);
                        cout << "Dimensiunea noua a vectorului: " << vec.size << endl;

                        cout << "Introduceti noile elemente ale vectorului: ";
                    for (int i = size; i < vec.size; i++) {
                        cin >> vec.elements[i];
                    }
                }
                break;
            case 5:
                elimina(vec);
                return 0;
            default:
                cout << "Optiune invalida. Va rugam incercati din nou." << endl;}
    }
return 0;
}
