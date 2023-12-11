#include <iostream>

using namespace std;

class Set {
private:
    int* elements;
    int size;
    int volum;

public:

    Set() {
        size = 0;
        volum = 10;
        elements = new int[volum];
    }

    ~Set() {
        delete[] elements;
    }

    // Adauga un element in multime
    void add(int element) {
        // Verificam daca elementul nu exista deja in multime
        if (findElement(element) == size) {
            // Verificam daca trebuie sa realocam memorie
            if (size == volum) {
                volum *= 2;
                int* newElements = new int[volum];
                copy(elements, elements + size, newElements);
                delete[] elements;
                elements = newElements;
            }
            elements[size++] = element;
        }
    }

    // Metoda pentru a gasi un element in multime
    int findElement(int element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return i;
            }
        }
        return size; // Returneaza size daca elementul nu este gasit
    }

        // Operatia de uniune
    Set operator+(const Set& other) const {
        Set result = *this; // Se creează o copie a obiectului curent (this) pentru a nu modifica setul original
        for (int i = 0; i < other.size; ++i) {
            result.add(other.elements[i]); // Se adaugă fiecare element din alt set în rezultat
        }
        return result;
    }


        // Operatia de intersectie
    Set operator*(const Set& other) const {
        Set result; // Se creează un set gol pentru a stoca rezultatul intersectiei
        for (int i = 0; i < size; ++i) {
            // Se verifică dacă elementul curent din setul curent există și în setul 'other'
            if (other.findElement(elements[i]) != other.size) {
                result.add(elements[i]); // Dacă există, se adaugă în setul rezultat
            }
        }
        return result; // Se returnează rezultatul intersectiei
    }


        // Operația de scădere
    Set operator-(const Set& other) const {
        Set result; // Se creează un set gol pentru a stoca rezultatul operației de scădere
        for (int i = 0; i < size; ++i) {
            // Se verifică dacă elementul curent din setul curent nu există în setul 'other'
            if (other.findElement(elements[i]) == other.size) {
                result.add(elements[i]); // Dacă nu există, se adaugă în setul rezultat
            }
        }
        return result; // Se returnează rezultatul operației de scădere
    }


    // Operatorul de comparare la egalitate
    friend bool operator==(const Set& set1, const Set& set2);

    // Operatorul +=
    friend Set& operator+=(Set& set, int element);

    // Afiseaza continutul multimii
    void display() const {
        for (int i = 0; i < size; ++i) {
            cout << elements[i] << " ";
    }
        cout << endl;
}

    //Apartenența la un set
    bool contine(int element) const {
        for (int i = 0; i < size; ++i) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }

    // Adaugati functii prietene pentru operatorii de inserție și extragere
    friend ostream& operator<<(ostream& os, const Set& set);
    friend istream& operator>>(istream& is, Set& set);
};

        // Implementarea funcției prietene de comparare la egalitate
    bool operator==(const Set& set1, const Set& set2) {
        // Verificăm dacă dimensiunile seturilor sunt diferite
        if (set1.size != set2.size) {
            return false; // Seturile nu pot fi egale dacă au dimensiuni diferite
        }

        // Parcurgem elementele setului 1
        for (int i = 0; i < set1.size; ++i) {
            // Verificăm dacă elementul curent din setul 1 există în setul 2
            if (set2.findElement(set1.elements[i]) == set2.size) {
                return false; // Dacă nu există, seturile nu sunt egale
            }
        }

        // Dacă nu s-a găsit nicio diferență, seturile sunt egale
        return true;
    }

    // Operatorul +=
   Set& operator+=(Set& set, int element) {
        set.add(element); // Adaugă elementul în set
        return set;}

    // Implementarea operatorului de inserție
    ostream& operator<<(ostream& os, const Set& set) {
        for (int i = 0; i < set.size; ++i) {
            os << set.elements[i] << " ";
        }
        return os;
    }

    // Implementarea operatorului de extragere
    istream& operator>>(istream& is, Set& set) {
        int numElements;
        cout << "Introduceti numarul de elemente: ";
        is >> numElements;

        cout << "Introduceti elementele:\n";
        for (int i = 0; i < numElements; ++i) {
            int element;
            cout << "Element " << i + 1 << ": ";
            is >> element;
            set.add(element);
        }

        return is;
    }

int main() {

    Set set1, set2;

    // Utilizare operatorul de extragere (>>)
    cout << "Introduceti elemente pentru Set 1:\n";
    cin >> set1;

    cout << "Introduceti elemente pentru Set 2:\n";
    cin >> set2;

    // Utilizare operatorul de inserție (<<)
    cout << "Set 1: " << set1 << endl;
    cout << "Set 2: " << set2 << endl;


    int numElementsSet1, numElementsSet2;

    // Citire elemente pentru Set 1
    cout << "Introduceti numarul de elemente pentru Set 1: ";
    cin >> numElementsSet1;

    cout << "Introduceti elementele pentru Set 1:\n";
    for (int i = 0; i < numElementsSet1; ++i) {
        int element;
        cout << "Element " << i + 1 << ": ";
        cin >> element;
        set1.add(element);
    }

    // Citire elemente pentru Set 2
    cout << "Introduceti numarul de elemente pentru Set 2: ";
    cin >> numElementsSet2;

    cout << "Introduceti elementele pentru Set 2:\n";
    for (int i = 0; i < numElementsSet2; ++i) {
        int element;
        cout << "Element " << i + 1 << ": ";
        cin >> element;
        set2.add(element);
    }
    // Operatii pe multimi
    Set unionSet = set1 + set2;
    Set intersectionSet = set1 * set2;
    Set scadereSet = set1 - set2;

    // Afisare rezultate
    cout << "Set 1: ";
    set1.display();

    cout << "Set 2: ";
    set2.display();

    cout << "Uniune: ";
    unionSet.display();

    cout << "Intersectie: ";
    intersectionSet.display();

    cout << "Scadere: ";
    scadereSet.display();

    if (set1 == set2) {
        cout << "Cele doua multimi sunt egale.\n";
    } else {
        cout << "Cele doua multimi nu sunt egale.\n";
    }

    // Adăugare elemente noi până când utilizatorul răspunde "Nu"
    string raspuns;
    while (true) {
        cout << "Doriti sa introduceti un element nou? (Da/Nu): ";
        cin >> raspuns;

        if (raspuns == "Nu" || raspuns == "nu") {
            break;
        }

        int newElement;
        cout << "Introduceti elementul nou: ";
        cin >> newElement;

        char setChoice;
        cout << "In care multime doriti sa adaugati elementul? (1 pentru Set 1, 2 pentru Set 2): ";
        cin >> setChoice;

        if (setChoice == '1' || setChoice == '2') {
            if (setChoice == '1') {
                set1 += newElement;
            } else {
                set2 += newElement;
            }

            cout << "Set 1 dupa adaugare: ";
            set1.display();

            cout << "Set 2 dupa adaugare: ";
            set2.display();

        } else {
            cout << "Selectie imposibila.";
        }
    }

    // Operații pe mulțimi
    Set unionSet2 = set1 + set2;
    Set intersectionSet2 = set1 * set2;
    Set scadereSet2 = set1 - set2;

    // Afișare rezultate
    cout << "Set 1: ";
    set1.display();

    cout << "Set 2: ";
    set2.display();

    cout << "Uniune: ";
    unionSet2.display();

    cout << "Intersectie: ";
    intersectionSet2.display();
    cout << "Scadere: ";
    scadereSet2.display();

    int check1;
    cout << "Introduceti elementul pentru verificare in Set 1: ";
    cin >> check1;

    if (set1.contine(check1)) {
        cout << check1 << " apartine multimii Set 1.\n";
    } else {
        cout << check1 << " nu apartine multimii Set 1.\n";
    }

    int check2;
    cout << "Introduceti elementul pentru verificare in Set 2: ";
    cin >> check2;

    if (set2.contine(check2)) {
        cout << check2 << " apartine multimii Set 2.\n";
    } else {
        cout << check2 << " nu apartine multimii Set 2.\n";
    }

    return 0;
}
