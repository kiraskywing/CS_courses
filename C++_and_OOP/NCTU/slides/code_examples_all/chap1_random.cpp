#include<iostream>
#include<ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    const unsigned int sizeOfArray = 10;
    int numberArray[sizeOfArray];

    for (int i = 0; i < sizeOfArray; i++)
    {
        numberArray[i] = rand() % 50;
        cout << numberArray[i] << endl;
    }

    for (int i = 0; i < sizeOfArray; i++)
    {
        cout << numberArray[i] << endl;
    }

    system("PAUSE");

    return 0;
}
