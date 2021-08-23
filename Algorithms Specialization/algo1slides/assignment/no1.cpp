#include <iostream>
#include <string>

using namespace std;

string multipler(string& s1, string& s2);
string adder(string& s1, string& s2);
string substractor(string& s1, string& s2);

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    // string res = multipler(s1, s2);
    // string res = adder(s1, s2);
    string res = substractor(s1, s2);
    cout << res << endl;

    return 0;
}

string multipler(string& s1, string& s2) {
    if (s1.size() == 1 || s2.size() == 1) {
        int a = stoi(s1), b = stoi(s2);
        return to_string(a * b);
    }

    int n1 = s1.size(), n2 = s2.size();
    string a = s1.substr(0, n1 / 2), b = s1.substr(n1 / 2);
    string c = s2.substr(0, n2 / 2), d = s2.substr(n2 / 2);
    string a_b = adder(a, b), c_d = adder(c, d);
    string sub1 = multipler(a, c), sub2 = multipler(b, d), sub3 = multipler(a_b, c_d);


    return s1;
}

string adder(string& s1, string& s2) {
    int i = s1.size() - 1, j = s2.size() - 1, nxt = 0;
    string res;
    while (i >= 0 && j >= 0) {
        int cur = (s1[i] - '0') + (s2[j] - '0') + nxt;
        res += ('0' + cur % 10);
        nxt = cur / 10;
        i--;
        j--;
    }
    while (i >= 0) {
        int cur = (s1[i] - '0') + nxt;
        res += ('0' + cur % 10);
        nxt = cur / 10;
        i--;
    }
    while (j >= 0) {
        int cur = (s2[j] - '0') + nxt;
        res += ('0' + cur % 10);
        nxt = cur / 10;
        j--;
    }
    if (nxt)
        res += '1';
    
    reverse(res.begin(), res.end());
    return res;
}

string substractor(string& s1, string& s2) {
    int i = s1.size() - 1, j = s2.size() - 1, nxt = 0, cur;
    string res;

    while (i >= 0 && j >= 0) {
        cur = (s1[i] - '0') - (s2[j] - '0') - nxt;
        if (cur < 0) {
            cur += 10;
            nxt = 1;
        }
        else
            nxt = 0;
        res += ('0' + cur);
        i--;
        j--;
    }
    while (i >= 0) {
        cur = (s1[i] - '0') - nxt;
        if (cur < 0) {
            cur += 10;
            nxt = 1;
        }
        else
            nxt = 0;
        res += ('0' + cur);
        i--;
    }
    while (j >= 0) {
        cur = (s2[j] - '0') - nxt;
        if (cur < 0) {
            cur += 10;
            nxt = 1;
        }
        else
            nxt = 0;
        res += ('0' + cur);
        j--;
    }
    
    reverse(res.begin(), res.end());
    return res;
}