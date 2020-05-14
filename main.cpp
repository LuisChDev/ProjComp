#include <iostream>
#include "./binario/binario.h"
#include "./decimal/decimal.h"
using namespace std;

/*
 * En este programa, vamos a escoger entre tres diferentes bases numéricas
 * y realizar operaciones sobre ellas.
 */

int main() {
  int input;
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
