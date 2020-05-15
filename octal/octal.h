#ifndef OCTAL_H
#define OCTAL_H

#include <iostream>
using namespace std;

class octal {
  friend ostream &operator<<(ostream &, const octal &);

public:
  octal(long = 0);
  octal operator+(const octal &) const;
  octal operator-(const octal &) const;

private:
  short dec[10];
  bool signo = true;
  void invertir();
  bool esMayor(const octal &) const;
};

#endif // OCTAL_H
