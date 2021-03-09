#include<iostream>

using namespace std;

int main()
{

    int *intPtr = new int;
    *intPtr = 10;

    cout << intPtr << " " << *intPtr << endl;

    delete intPtr;

    system("PAUSE");

    return 0;
}
