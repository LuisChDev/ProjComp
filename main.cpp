#include <iostream>
#include "./binario/binario.h"
#include "./decimal/decimal.h"
#include "./octal/octal.h"
using namespace std;

/*
 * En este programa, vamos a escoger entre tres diferentes bases numéricas
 * y realizar operaciones sobre ellas.
 */

int main() {
  int input, input2, numero, numero2;
  cout << "Bienvenido al programa." << endl << endl;

  do {
    cout << "Sistemas Numéricos:" << endl;
    cout << "1. Decimal" << endl
         << "2. Octal" << endl
         << "3. Binario" << endl
         << "4. Salir" << endl;
    cout << endl << "Escoja opción: " << endl;

    cin >> input;

    switch (input) {

    case 1:
      cout << "operaciones decimales." << endl;
      do {
        cout << "1. Suma" << endl
             << "2. Resta" << endl
             << "3. Salir" << endl
             << endl
             << "Escoja opción: " << endl;
        cin >> input2;

        switch (input2) {

        case 1:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La suma da " << (decimal(numero) + decimal(numero2)) << endl;
          break;

        case 2:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La resta da " << (decimal(numero) - decimal(numero2)) << endl;

          break;

        case 3:
          break;

        default:
          cout << "opción inválida. Por favor ingrese de nuevo." << endl;
          cin.clear();
          cin.ignore();
        }
      } while (input2 != 3);
      break;

    case 2:
      cout << "operaciones octales." << endl;
      do {
        cout << "1. Suma" << endl
             << "2. Resta" << endl
             << "3. Salir" << endl
             << endl
             << "Escoja opción: " << endl;
        cin >> input2;

        switch (input2) {

        case 1:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La suma da " << (octal(numero) + octal(numero2)) << endl;
          break;

        case 2:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La resta da " << (octal(numero) - octal(numero2)) << endl;

          break;

        case 3:
          break;

        default:
          cout << "opción inválida. Por favor ingrese de nuevo." << endl;
          cin.clear();
          cin.ignore();
        }
      } while (input2 != 3);
      break;

    case 3:
      cout << "operaciones binarias." << endl;
      do {
        cout << "1. Suma" << endl << "2. Resta" << endl << "3. Salir" <<
          endl << endl << "Escoja opción: " << endl;
        cin >> input2;

        switch (input2) {

        case 1:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La suma da " << (binario(numero) + binario(numero2)) << endl;
          break;

        case 2:
          cout << "Por favor ingrese el primer número: " << endl;
          cin >> numero;
          cout << "Por favor ingrese el segundo: " << endl;
          cin >> numero2;

          cout << "La resta da " << (binario(numero) - binario(numero2)) << endl;
          break;

        case 3:
          break;

        default:
          cout << "opción inválida. Por favor ingrese de nuevo." << endl;
          cin.clear();
          cin.ignore();
        }
      } while (input2 != 3);
      break;

    case 4:
      break;

    default:
      cout << "Entrada inválida. Por favor ingrese de nuevo." << endl;
      cin.clear();
      cin.ignore();
    }

  } while (input != 4);

  cout << "Gracias por usar el programa." << endl;

  return 0;
}
