#include<iostream>

using namespace std;

int main()
{
    int a = 10;
    int b = 120;

    int &r = a; // r became a
    int *p1 = &a;
    int *p2 = &b;

    cout << r << endl;
    r = b; //r OR a's value is changed to 120!!!!!
    cout << r << endl;
    cout << a << endl;


    system("PAUSE");

    return 0;
}
