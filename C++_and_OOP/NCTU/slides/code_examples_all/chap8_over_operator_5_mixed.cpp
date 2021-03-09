#include <iostream>

using namespace std;

class Complex {
public:
  Complex(double re = 0.0, double im = 0.0) : re(re), im(im) {}
    
public:
    
    Complex operator+(const Complex& complex) {
        Complex _complex;
        _complex.re = this->re + complex.re;
        _complex.im = this->im + complex.im;
        return _complex;
    }
    friend Complex operator*(const Complex& complex1, const Complex&);
  friend ostream& operator<<(ostream&, const Complex&);
    
private:
  double re; // real part
  double im; // imagenary part
};

Complex operator*(const Complex& complex1, const Complex& complex2) {
  Complex _complex;
  _complex.re = complex1.re * complex2.re - complex1.im * complex2.im;
  _complex.im = complex1.re * complex2.im + complex1.im * complex2.re;
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
