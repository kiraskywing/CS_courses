#include <iostream>

using namespace std;

int add(int a, int b){
	return a + b;
}

void sub(int *a, int *b, int *c){
	*c = *a - *b;
}

void mul(int a, int b, int &c){
	c = a * b;
}

void div(int *a, int b, int &c){
	c = (*a) / b;
}

int main() {
    int num1;
    int num2;
    
    cin >> num1 >> num2;
    
    int value = 0;
    value = add(num1, num2);
    cout << value << " ";
    sub(&num1, &num2, &value);
    cout << value << " ";
    mul(num1, num2, value);
    cout << value << " ";
    div(&num1, num2, value);
    cout << value << endl;
    return 0;
}