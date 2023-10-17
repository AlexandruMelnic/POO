#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ProdusSoft {
    string denumire;
    string firmaProducere;
    int anEditare;
    float versiune;
};

void setareDate(ProdusSoft *produs) {
    cout << "Introduceti denumirea: ";

    cin >> produs->denumire;

    cout << "Introduceti firma de producere: ";
    cin >> produs->firmaProducere;

    cout << "Introduceti anul editarii: ";
    cin >> produs->anEditare;

    cout << "Introduceti versiunea: ";
    cin >> produs->versiune;

    cout << endl;
}

void modificareDate(ProdusSoft  *produs) {
    int optiune;
    cout << endl;
    cout << "Alegeti ce camp doriti sa modificati:" << endl;
    cout << "1. Denumire" << endl;
    cout << "2. Firma de producere" << endl;
    cout << "3. Anul editarii" << endl;
    cout << "4. Versiune" << endl;
    cout << "Optiune: ";
    cin >> optiune;
    cout << endl;

    switch (optiune) {
        case 1:
            cout << "Introduceti noua denumire: ";
            cin >> produs->denumire;
            break;
        case 2:
            cout << "Introduceti noua firma de producere: ";
            cin >> produs->firmaProducere;
            break;
        case 3:
            cout << "Introduceti noul an de editare: ";
            cin >> produs->anEditare;
            break;
        case 4:
            cout << "Introduceti noua versiune: ";
            cin >> produs->versiune;
            break;
        default:
            cout << "Optiune invalida." << endl;
    }
}

void cautaProdus(ProdusSoft **produse, int numarProduse) {
    int optiune;
    cout << endl << "Alegeti criteriul de cautare:" << endl;
    cout << "1. Denumire" << endl;
    cout << "2. Firma de producere" << endl;
    cout << "3. Anul editarii" << endl;
    cout << "4. Versiune" << endl;
    cout << "Optiune: ";
    cin >> optiune;
    cout << endl;

    string valoareCautata;

    switch (optiune) {
        case 1:
            cout << "Introduceti denumirea cautata: ";
            cin >> valoareCautata;
            for (int i = 0; i < numarProduse; i++) {
                if (produse[i]->denumire == valoareCautata) {
cout << "Produsul " << i+1 << ": " << endl << "Denumire: " << produse[i]->denumire << endl << "Firma: " << produse[i]->firmaProducere << endl << "Anul: " << produse[i]->anEditare << endl << "Versinea: " << produse[i]->versiune << endl;
                }
            }
            break;
        case 2:
            cout << "Introduceti firma de producere cautata: ";
            cin >> valoareCautata;
            for (int i = 0; i < numarProduse; i++) {
                if (produse[i]->firmaProducere == valoareCautata) {
cout << "Produsul " << i+1 << ": " << endl << "Denumire: " << produse[i]->denumire << endl << "Firma: " << produse[i]->firmaProducere << endl << "Anul: " << produse[i]->anEditare << endl << "Versinea: " << produse[i]->versiune << endl;
                }
            }
            break;
        case 3:
            int anCautat;
            cout << "Introduceti anul editarii cautat: ";
            cin >> anCautat;
            for (int i = 0; i < numarProduse; i++) {
                if (produse[i]->anEditare == anCautat) {
cout << "Produsul " << i+1 << ": " << endl << "Denumire: " << produse[i]->denumire << endl << "Firma: " << produse[i]->firmaProducere << endl << "Anul: " << produse[i]->anEditare << endl << "Versinea: " << produse[i]->versiune << endl;
                }
            }
            break;
        case 4:
            float versiuneCautata;
            cout << "Introduceti versiunea cautata: ";
            cin >> versiuneCautata;
            for (int i = 0; i < numarProduse; i++) {
                if (produse[i]->versiune == versiuneCautata) {
cout << "Produsul " << i+1 << ": " << endl << "Denumire: " << produse[i]->denumire << endl << "Firma: " << produse[i]->firmaProducere << endl << "Anul: " << produse[i]->anEditare << endl << "Versinea: " << produse[i]->versiune << endl;
                }
            }
            break;
        default:
            cout << "Optiune invalida." << endl;
    }

}
bool comparareDupaVersiune(const ProdusSoft *produs1, const ProdusSoft *produs2) {
    return produs1->versiune < produs2->versiune;
}


void eliberareMemorie(ProdusSoft **produse, int numarProduse) {
    for (int i = 0; i < numarProduse; i++) {
        delete produse[i];
    }
    delete[] produse;
}

int main() {
    int numarProduse;
    cout << "Cate produse aveti nevoie? ";
    cin >> numarProduse;

    ProdusSoft **produse = new ProdusSoft*[numarProduse];

    for (int i = 0; i < numarProduse; i++) {
        produse[i] = new ProdusSoft;
        setareDate(produse[i]);
    }
    int optiuneSortare;
do {
    cout << "Doriti sa sortati produsele dupa versiune? (1 - Da, 0 - Nu): ";
    cin >> optiuneSortare;
    if (optiuneSortare) {
        // Sortați produsele aici
        sort(produse, produse + numarProduse, comparareDupaVersiune);

        // Afișați produsele sortate
        for (int i = 0; i < numarProduse; i++) {
            cout << "Produsul " << i + 1 << ": " << endl
                 << "Denumire: " << produse[i]->denumire << endl
                 << "Firma: " << produse[i]->firmaProducere << endl
                 << "Anul: " << produse[i]->anEditare << endl
                 << "Versiunea: " << produse[i]->versiune << endl;
        }
    }
} while (optiuneSortare);


    int optiune;
    do {
        cout << "Doriti sa faceti modificari asupra produselor? (1 - Da, 0 - Nu): ";
        cin >> optiune;

        if (optiune) {
            int indexProdus;
            cout << "Introduceti indexul produsului pe care doriti sa il modificati: ";
            cin >> indexProdus;

            if (indexProdus >= 0 && indexProdus < numarProduse) {
                modificareDate(produse[indexProdus]);
            } else {
                cout << "Indexul invalid." << endl;
            }
        }
    } while (optiune);

    cautaProdus(produse, numarProduse);

    int optiuneCautare;
    do {
        cout << endl;
        cout << "Doriti sa mai cautati? (1 - Da, 0 - Nu): ";
        cin >> optiuneCautare;
        if (optiuneCautare) {
            cautaProdus(produse, numarProduse);
        }
    } while (optiuneCautare);

    eliberareMemorie(produse, numarProduse);

    return 0;
}
