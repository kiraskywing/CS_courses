#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <random>
using namespace std;

typedef pair<int, int> iPair;

random_device rd;
default_random_engine generator(rd());

void reduceInput(unordered_set<int>&, unordered_set<int>&, vector<iPair>&);
int randFlip(void);

int main(void) {
    int n, a, b;
    cin >> n;
    vector<int> variables(n + 1, 0);
    vector<iPair> clauses(n);
    unordered_set<int> validVariables, validCIdx;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        clauses[i].first = a; clauses[i].second = b;
        validVariables.insert(abs(a));
        validVariables.insert(abs(b));
        validCIdx.insert(i);
    }

    reduceInput(validVariables, validCIdx, clauses);
    // for (int i : validCIdx)
    //     cout << '(' << clauses[i].first << " v " << clauses[i].second << ") ^";
    // cout << endl;

    n = validVariables.size();
    int times = (int)(ceil(log(n) / log(2)));
    for (int i = 0; i < times; i++) {
        for (int i : validVariables)
            variables[i] = randFlip();
        for (int j = 0; j < n * n * 2; j++) {
            int check = validCIdx.size();
            
            // for (int i : validVariables) {
            //     cout << i << ':' << variables[i] << ", ";
            // }
            // cout << endl;
            
            for (int k : validCIdx) {
                int a = clauses[k].first, b = clauses[k].second;
                int a_abs = abs(a), b_abs = abs(b);
                
                if (((a < 0 && !variables[a_abs]) || (a > 0 && variables[a_abs])) || ((b < 0 && !variables[b_abs]) || (b > 0 && variables[b_abs]))) {
                    check--;
                    if (!check) {
                        cout << "Valid assignment found\n";
                        return 0;
                    }
                }
                else {
                    randFlip() ? variables[a_abs] ^= 1 : variables[b_abs] ^= 1;
                    break;
                }
            }
        }
    }
    cout << "No valid assignment found\n";

    return 0;
}

void reduceInput(unordered_set<int>& variables, unordered_set<int>& validCIdx, vector<iPair>& clauses) {
    unordered_map<int, iPair> checkBool;
    unordered_set<int> nxtCIdx;
    int vSize;
    do {
        vSize = variables.size();
        checkBool.clear(); nxtCIdx.clear();

        for (int i : validCIdx) {
            int a = clauses[i].first, b = clauses[i].second;
            int a_abs = abs(a), b_abs = abs(b);
            
            if (!checkBool.count(a_abs))
                checkBool[a_abs].first = checkBool[a_abs].second = 0;
            a < 0 ? checkBool[a_abs].first = 1 : checkBool[a_abs].second = 1;
            if (!checkBool.count(b_abs))
                checkBool[b_abs].first = checkBool[b_abs].second = 0;
            b < 0 ? checkBool[b_abs].first = 1 : checkBool[b_abs].second = 1;
        }

        variables.clear();
        for (auto& cur : checkBool) {
            if (cur.second.first && cur.second.second)
                variables.insert(cur.first);
        }

        for (int i : validCIdx) {
            int a = abs(clauses[i].first), b = abs(clauses[i].second);
            if (variables.count(a) && variables.count(b))
                nxtCIdx.insert(i);
        }

        validCIdx.clear();
        validCIdx.insert(nxtCIdx.begin(), nxtCIdx.end());

    } while (vSize != variables.size());
    
    // cout << variables.size() << ' ' << validCIdx.size() << endl;
}

int randFlip(void) {
    uniform_int_distribution<int> distribution(0, 1);
    return distribution(generator);
}