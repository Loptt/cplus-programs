//
// Created by charles on 16/04/18.
//

#include "Fecha.h"

int main() {

    Fecha f1, f2, f3, f4, f5, f6;

    int op;
    // opcion 1 ==, 2 +, 3 <=, 4 >=, 5 >, 6 <
    cin >> op;

    cin >> f1 >> f2 >> f3;

    switch (op) {

        case 1: {
            if (f1 == f2) {
                cout << f1 << " si es igual a " << f2 << endl;
            } else {
                cout << f1 << " no es igual a " << f2 << endl;
            }
            if (f1 == f3) {
                cout << f1 << " si es igual a " << f3 << endl;
            } else {
                cout << f1 << " no es igual a " << f3 << endl;
            }
            if (f2 == f3) {
                cout << f2 << " si es igual a " << f3 << endl;
            } else {
                cout << f2 << " no es igual a " << f3 << endl;
            }
            break;
        }
        case 2: {
            f4 = f1 + 1;
            f5 = f2 + 5;
            f6 = f3 + 10;
            cout << f4 << endl;
            cout << f5 << endl;
            cout << f6 << endl;
            break;
        }
        case 3: {
            if (f1 <= f2) {
                cout << f1 << " es <= a " << f2 << endl;
            } else {
                cout << f1 << " no es <= a " << f2 << endl;
            }
            if (f1 <= f3) {
                cout << f1 << " es <= a " << f3 << endl;
            } else {
                cout << f1 << " no es <= a " << f3 << endl;
            }
            if (f2 <= f3) {
                cout << f2 << " es <= a " << f3 << endl;
            } else {
                cout << f2 << " no es <= a " << f3 << endl;
            }
            break;
        }
        case 4: {
            if (f1 >= f2) {
                cout << f1 << " es >= a " << f2 << endl;
            } else {
                cout << f1 << " no es >= a " << f2 << endl;
            }
            if (f1 >= f3) {
                cout << f1 << " es >= a " << f3 << endl;
            } else {
                cout << f1 << " no es >= a " << f3 << endl;
            }
            if (f2 >= f3) {
                cout << f2 << " es >= a " << f3 << endl;
            } else {
                cout << f2 << " no es >= a " << f3 << endl;
            }
            break;
        }
        case 5: {
            if (f1 > f2) {
                cout << f1 << " es > a " << f2 << endl;
            } else {
                cout << f1 << " no es > a " << f2 << endl;
            }
            if (f1 > f3) {
                cout << f1 << " es > a " << f3 << endl;
            } else {
                cout << f1 << " no es > a " << f3 << endl;
            }
            if (f2 > f3) {
                cout << f2 << " es > a " << f3 << endl;
            } else {
                cout << f2 << " no es > a " << f3 << endl;
            }
            break;
        }
        case 6: {
            if (f1 < f2) {
                cout << f1 << " es < a " << f2 << endl;
            } else {
                cout << f1 << " no es < a " << f2 << endl;
            }
            if (f1 < f3) {
                cout << f1 << " es < a " << f3 << endl;
            } else {
                cout << f1 << " no es < a " << f3 << endl;
            }
            if (f2 < f3) {
                cout << f2 << " es < a " << f3 << endl;
            } else {
                cout << f2 << " no es < a " << f3 << endl;
            }
            break;

        }
    }

    return 0;
}

