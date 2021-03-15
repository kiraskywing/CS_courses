#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Student {
public:
	Student( ) { }
	string generate_address(){
        string s1 = "1001 University Road, Hsinchu, Taiwan 300, ROC, dorm ";
        string s2 = ", (";
        string s3 = ") ";
        string s4 = " "; 
        string res = s1 + dormitory + s2 + ID + s3 + first_name + s4 + last_name;
        return res;
    	//TODO        
    }
    void set_info(string fname, string lname, string dm, string id) {
        first_name = fname;
        last_name = lname;
        dormitory = dm;
        ID = id;
    }
  	//Please implement the remain class
private:
	string first_name;
    string last_name;
	string dormitory;
	string ID;
};


int main() {
  	Student mStudent;
    /* Enter your code here. Read input from STDIN */
    string fname, lname, dm, id;
    cin >> fname >> lname >> dm >> id;
    mStudent.set_info(fname, lname, dm, id);
  	cout << mStudent.generate_address() << endl;
    return 0;
}