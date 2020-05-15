#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
using namespace std;

class decimal {
  friend ostream &operator<<(ostream &, const decimal &);

public:
  decimal(long = 0);
  decimal operator+(const decimal &) const;
  decimal operator-(const decimal &) const;

private:
  short dec[10];
  bool signo = true;
  void invertir();
  bool esMayor(const decimal &) const;
};

#endif // DECIMAL_H
