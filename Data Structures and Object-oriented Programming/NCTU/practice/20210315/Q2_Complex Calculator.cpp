#include <iostream>

using namespace std;

class Complex{
public:
    Complex(){}
    Complex(float r_val, float i_val){
        real = r_val;
        image = i_val;
        //TO DO
    }
    const Complex operator+(const Complex& k){
        float new_real, new_image;
        new_real = real + k.getReal();
        new_image = image + k.getImage();
        return Complex(new_real, new_image);
        // TO DO
    }
    const Complex operator-(const Complex& k){
        float new_real, new_image;
        new_real = real - k.getReal();
        new_image = image - k.getImage();
        return Complex(new_real, new_image);
        // TO DO
    }
    float getReal() const{
        return real;
        // TO DO
    }
    float getImage() const{
        return image;
        // TO DO
    }
private:
    float real,image;
};

ostream& operator<<(ostream& out,const Complex& k){
    float real, image;
    real = k.getReal();
    image = k.getImage();
    if(image >= 0)out<<real<<" + "<<image<<"i";
      else out<<real<<" - "<<-image<<"i";
    return out;
}

int main(){
    float real1, image1;
    float real2, image2;
    while(cin >> real1 >> image1 >> real2 >> image2){
        Complex myComplex1(real1, image1);
        Complex myComplex2(real2, image2);
        cout<< myComplex1 + myComplex2 << endl;
        cout<< myComplex1 - myComplex2 << endl;
    }
    return 0;
}