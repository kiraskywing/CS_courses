#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}
    
public:
  Complex operator+(const Complex& complex);
  Complex operator*(const Complex& complex);
  friend ostream& operator<<(ostream&, const Complex&);
    
private:
  double re; // real part
  double im; // imagenary part
};


Complex Complex::operator+(const Complex& complex) {
  Complex _complex;
  _complex.re = this->re + complex.re;
  _complex.im = this->im + complex.im;
  return _complex;
}

Complex Complex::operator*(const Complex& complex) {
  Complex _complex;
    _complex.re = this->re * complex.re - this->im * complex.im;
    _complex.im = this->re * complex.im + this->im * complex.re;
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
