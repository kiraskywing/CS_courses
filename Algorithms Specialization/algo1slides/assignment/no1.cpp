#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string multipler(string& s1, string& s2);
string adder(string& s1, string& s2);
string substractor(string& s1, string& s2);
string brute_force_multi(string& s1, string& s2);

int main(void) {
    string s1, s2;
    cin >> s1 >> s2;

    string res = brute_force_multi(s1, s2);
    cout << res << endl;

    res = multipler(s1, s2);
    cout << res << endl;

    return 0;
}

string brute_force_multi(string& s1, string& s2) {
    int n1 = s1.size(), n2 = s2.size();
    string res;

    for (int j = n2 - 1; j >= 0; j--) {
        string cur;
        int num, nxt = 0;
        for (int i = n1 - 1; i >= 0; i--) {
            num = (s2[j] - '0') * (s1[i] - '0') + nxt;
            cur += '0' + num % 10;
            nxt = num / 10;
        }
        if (nxt)
            cur += '0' + nxt;
        reverse(cur.begin(), cur.end());
        cur += string(n2 - 1 - j, '0');
        res = adder(res, cur);
    }

    return res;
}

string multipler(string& s1, string& s2) {
    // cout << "s1: " << s1 << ", s2: " << s2 << endl;
    if (s1.size() == 1) {
        return brute_force_multi(s2, s1);
    }
    if (s2.size() == 1) {
        return brute_force_multi(s1, s2);
    }

    int n1 = s1.size(), n2 = s2.size();
    int half = min(n1, n2) / 2;
    string a = s1.substr(0, n1 - half), b = s1.substr(n1 - half, half);
    string c = s2.substr(0, n2 - half), d = s2.substr(n2 - half, half);
    // cout << "a: " << a << ", b: " << b << ", c: " << c << ", d: " << d << endl;

    string a_b = adder(a, b), c_d = adder(c, d);
    string sub1 = multipler(a, c), sub2 = multipler(b, d), sub3 = multipler(a_b, c_d);
    
    sub3 = substractor(sub3, sub1);
    sub3 = substractor(sub3, sub2);
    sub3 += string(half, '0');
    sub1 += string(half * 2, '0');
    
    string res = adder(sub1, sub2);
    res = adder(res, sub3);

    // cout << "a * c: " << sub1 << ", b * d: " << sub2 << ", (ad + bc): " << sub3
    //      << ", res: " << res << endl;

    return res;
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
    i = 0;
    while (res[i] == '0')
        i++;
    return res.substr(i);
}