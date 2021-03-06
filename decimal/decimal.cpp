#include "decimal.h"

/**
 * constructor predeterminado
 */
decimal::decimal(long valor) {
    for(int i = 0; i <= 9; i++)
        dec[i] = 0;

    if (valor < 0) {
      signo = false;
      valor = valor*(-1);
    }

    /* coloca los digitos del argumento dentro del arreglo */
    for(int j = 9; valor != 0 && j >= 0; j--) {
        dec[j] = valor % 10;
        valor /= 10;
    }
}

decimal decimal::operator+(const decimal &op2) const
{
    decimal temp;
    int acarreo = 0;
    for(int i = 9; i >= 0; i--){
        temp.dec[i] = dec[i] + op2.dec[i] + acarreo;
        if(temp.dec[i] > 9){
            temp.dec[i] %= 10; //reduce a 0-9
            acarreo = 1;
        }
        else
            acarreo = 0;
    }
    return temp;
}

/**
 * operador de inversión para la resta.
 * calcula el complemento de 9.
 */
void decimal::invertir() {
  for (int i = 0; i < 10; i++) {
    dec[i] = 9 - dec[i];
  }
}

/**
 * calcula cuál número es mayor.
 * útil para la resta.
 */
bool decimal::esMayor(const decimal& comp) const {
  for (int i = 0; i < 10; i++) {
    if (dec[i] > comp.dec[i]) {
      return true;
    } else if (dec[i] < comp.dec[i]) {
      return false;
    }
  }
  return false;
}

/**
 * calcula la sustracción usando una suma y el complemento de nueves.
 */
decimal decimal::operator-(const decimal &op2) const {
  decimal result;
  decimal minuInver = *this;
  minuInver.invertir();
  result = minuInver + op2;
  if (this->esMayor(op2)) {
    result.invertir();
  } else {
    result = result + decimal(1);
    result.signo = !result.signo;
  }

  return result;
}

/**
 *operador de salida sobrecargado
 */
ostream& operator<<(ostream &salida, const decimal &num)
{
    int i;
    for(i = 0; (num.dec[i] == 0) && (i <= 9); i++);
    /*ignora ceros a la izquierda*/

    if (!num.signo) {
      salida << "-";
    }

    if(i == 9 && num.dec[i] == 0)
        salida << 0;
    else
        for( ; i <= 9; i++)
            salida << num.dec[i];
    return salida;
}
