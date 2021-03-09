#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}
  double getRE() const {return re;}
  double getIM() const {return im;}
  void setRE(double re){this->re=re;}
  void setIM(double im){this->im=im;}
    
public:
  friend ostream& operator<<(ostream&, const Complex&);
    
private:
  double re; // real part
  double im; // imagenary part
};


Complex operator+(const Complex& complex1, const Complex& complex2) {
  Complex _complex;
  _complex.setRE(complex1.getRE() + complex2.getRE());
  _complex.setIM(complex1.getIM() + complex2.getIM());
  return _complex;
}

Complex operator*(const Complex& complex1, const Complex& complex2) {
  Complex _complex;
  _complex.setRE(complex1.getRE() * complex2.getRE() - complex1.getIM() * complex2.getIM());
  _complex.setIM(complex1.getRE() * complex2.getIM() + complex1.getIM() * complex2.getRE());
  return _complex;
}

ostream& operator<<(ostream& out, const Complex& complex) {
  out << "real:" << complex.re << " imagenary:" << complex.im;

  return out;
}

int main() {
  Complex complex1(2,2);
  Complex complex2(3,3);
  Complex complex3 = complex1 + complex2;
  Complex complex4 = complex1 * complex2;

  cout << complex3 << endl;
  cout << complex4 << endl;
}
