#include "binario.h"

/**
 * binario basado en la representación complemento de dos
 * los números positivos se representan normalmente, los negativos
 * con el último bit en 1 y su complemento de dos.
 * por ejemplo, usando 4 bits, 3 sería 0011, -3 sería 1101.
 * esta representación permite implementar la suma y la resta con una sola
 * función, más una función de inversión de signo.
 */

/**
 * invierte el signo del número.
 * simplemente invierte todos los dígitos, y suma 1.
 */
void binario::invertir() {
  for (int i = 0; i < 32; i++) {
    bin[i] = 2 - bin[i] - 1;
  }

  this->sumar(binario(1));
}

/**
 * constructor.
 */
binario::binario(long valor) {
  for (int i = 0; i < 32; i++) {
    bin[i] = 0;
  }

  // se guarda el signo del valor.
  bool signo = true;
  if (valor < 0) {
    signo = !signo;
    valor = valor * -1;
  }

  // se se agregan los dígitos normalmente.
  for (int i = 31; i >= 0 && valor != 0; i--) {
    bin[i] = valor % 2;
    valor /= 2;
  }

  // si el valor era negativo, se invierte el número.
  if (!signo) {
    this->invertir();
  }
}

/**
 * el algoritmo base de suma.
 */
void binario::sumar(const binario& sum2) {
  int lleva = 0;

  for (int i = 31; i >= 0; i--) {
    bin[i] += sum2.bin[i] + lleva;
    if (bin[i] > 1) {
      bin[i] %= 2;
      lleva = 1;
    } else {
      lleva = 0;
    }
  }
}

binario binario::operator+(const binario &op2) const {
  binario result = binario(0);
  int acarreo = 0;

  result.sumar(op2);
  result.sumar(*this);

  return result;
}

/**
 * operador de resta
 * simplemente se invierte el sustraendo y se suma.
 */
binario binario::operator-(const binario &sustr) const {
  binario result = binario(0);
  binario sus = sustr;
  sus.invertir();

  result.sumar(*this);
  result.sumar(sus);

  return result;
}

/**
 * operador de salida sobrecargado
 * si el número es negativo, se imprime un signo menos, se invierte e imprime el resto.
 */
ostream& operator<<(ostream &salida, const binario &num)
{
  int i;
  binario num2 = num;

  if (num2.bin[0] == 1) {
    salida << "-";
    num2.invertir();
  }

  for(i = 0; (num2.bin[i] == 0) && (i <= 31); i++);
  /* ignora ceros a la izquierda */

  if(i == 32)
    salida << 0;
  else
    for( ; i <= 31; i++)
      salida << num2.bin[i];
  return salida;
}

// Local Variables:
// ispell-local-dictionary: "castellano"
// End:
