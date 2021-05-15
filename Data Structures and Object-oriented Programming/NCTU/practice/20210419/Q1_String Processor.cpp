#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void trim(string &str){
	//TODO
    int i = 0;
    while (i < str.size() && str[i] == ' ')
        i++;
    str = str.substr(i);
    
    int j = str.size() - 1;
    while (j >= 0 && (str[j] == ' ' || str[j] == '\n'))
        j--;
    str = str.substr(0, j+1);
}


void reverse(string &str){
	//TODO 
    reverse(str.begin(), str.end());
}

int main()
{
    string input_line;
  	//TODO 
    getline(cin, input_line);
    trim(input_line);
    reverse(input_line);
    cout << input_line;
    return 0;
}