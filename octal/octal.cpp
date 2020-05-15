#include "octal.h"

/**
 * constructor predeterminado
 */
octal::octal(long valor) {
    for(int i = 0; i <= 9; i++)
        dec[i] = 0;

    if (valor < 0) {
      signo = false;
      valor = valor*(-1);
    }

    /* coloca los digitos del argumento dentro del arreglo */
    for(int j = 9; valor != 0 && j >= 0; j--) {
        dec[j] = valor % 8;
        valor /= 8;
    }
}

octal octal::operator+(const octal &op2) const
{
    octal temp;
    int acarreo = 0;
    for(int i = 9; i >= 0; i--){
        temp.dec[i] = dec[i] + op2.dec[i] + acarreo;
        if(temp.dec[i] > 7){
            temp.dec[i] %= 8; //reduce a 0-7
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
void octal::invertir() {
  for (int i = 0; i < 10; i++) {
    dec[i] = 7 - dec[i];
  }
}

/**
 * calcula cuál número es mayor.
 * útil para la resta.
 */
bool octal::esMayor(const octal& comp) const {
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
octal octal::operator-(const octal &op2) const {
  octal result;
  octal minuInver = *this;
  minuInver.invertir();
  result = minuInver + op2;
  if (this->esMayor(op2)) {
    result.invertir();
  } else {
    result = result + octal(1);
    result.signo = !result.signo;
  }

  return result;
}

/**
 *operador de salida sobrecargado
 */
ostream& operator<<(ostream &salida, const octal &num)
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
