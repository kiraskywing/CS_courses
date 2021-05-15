#include <iostream>

using namespace std;

int main(void)
{
    cout << "Hello world" << endl;
    cout << "Hello world\n";

    int num1, num2;
    double num3;
    cout << "Enter 2 integers seperated with white a space: ";
    cin >> num1 >> num2;
    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    cout << "Enter a double: ";
    cin >> num3;
    cout << "num3: " << num3 << endl;
    
    return 0;
}