#include <iostream>

using namespace std;

class Bool {
private:
    bool value; // Valoarea stocată

public:
    // Constructor implicit care setează valoarea la false
    Bool() {
    value = false;
}

    // Constructor care permite inițializarea cu o valoare specifică
    Bool(bool val) {
        value = val;
    }

    // Metodă pentru a obține valoarea stocată
    bool getValue() const {
        return value;
    }

    // Operatorii == și != ca metode ale clasei
    bool operator==(const Bool& other) const {
        return value == other.value;
    }

    bool operator!=(const Bool& other) const {
        return value != other.value;
    }

    // Funcții prietene pentru operatorii "+" (SAU), "*" (ȘI), "^" (SAU EXCLUSIV)
    friend Bool operator+(const Bool& left, const Bool& right);
    friend Bool operator*(const Bool& left, const Bool& right);
    friend Bool operator^(const Bool& left, const Bool& right);
};

// Funcții prietene pentru operatorii "+" (SAU), "*" (ȘI), "^" (SAU EXCLUSIV)
Bool operator+(const Bool& left, const Bool& right) {
    return Bool(left.getValue() || right.getValue());
}

Bool operator*(const Bool& left, const Bool& right) {
    return Bool(left.getValue() && right.getValue());
}

Bool operator^(const Bool& left, const Bool& right) {
    return Bool(left.getValue() != right.getValue());
}

// Operatorii pentru a permite operații cu variabilele de tip predefinit int
Bool operator+(const Bool& left, int right) {
    return Bool(left.getValue() || (right != 0));
}

Bool operator*(const Bool& left, int right) {
    return Bool(left.getValue() && (right != 0));
}

Bool operator^(const Bool& left, int right) {
    return Bool(left.getValue() != (right != 0));
}

Bool operator+(int left, const Bool& right) {
    return Bool((left != 0) || right.getValue());
}

Bool operator*(int left, const Bool& right) {
    return Bool((left != 0) && right.getValue());
}

Bool operator^(int left, const Bool& right) {
    return Bool((left != 0) != right.getValue());
}

// Funcția principală a programului
int main() {
    Bool b1(true);
    Bool b2(false);

    // Testarea operatorilor Bool și int
    Bool result1 = b1 + 1;  // b1 SAU 1 (true || true)  true
    Bool result2 = b2 * 0;  // b2 ȘI 0 (false && e)  false
    Bool result3 = b1 ^ 2;  // b1 SAU EXCLUSIV 2 (true XOR true)  false

    Bool result4 = 3 + b2;  // 3 SAU b2 (true || false)  true
    Bool result5 = 0 * b1;  // 0 ȘI b1 (false && true)  false
    Bool result6 = 1 ^ b2;  // 1 SAU EXCLUSIV b2 (true XOR false)  true

    Bool result_or = b1 + b2;
    Bool result_and = b1 * b2;
    Bool result_xor = b1 ^ b2;

    cout << "b1 + b2: " << result_or.getValue() << endl;
    cout << "b1 * b2: " << result_and.getValue() << endl;
    cout << "b1 ^ b2: " << result_xor.getValue() << endl;

    cout << "\nb1 + 1: " << result1.getValue() << endl;
    cout << "b2 * 0: " << result2.getValue() << endl;
    cout << "b1 ^ 2: " << result3.getValue() << endl;

    cout << "\n3 + b2: " << result4.getValue() << endl;
    cout << "0 * b1: " << result5.getValue() << endl;
    cout << "1 ^ b2: " << result6.getValue() << endl;

    //Testarea == și !=
    cout << endl;
        if (b1 == b2) {
        cout << "b1 este egal cu b2" << endl;
    } else {
        cout << "b1 nu este egal cu b2" << endl;
    }

    if (b1 != b2) {
        cout << "b1 nu este egal cu b2" << endl;
    } else {
        cout << "b1 este egal cu b2" << endl;
    }

    return 0;
}

