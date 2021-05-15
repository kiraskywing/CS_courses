#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) 
{
    int scores[] {10, 20, 30};
    
    for (auto score : scores)
        cout << score << endl;
        
    vector<double> temperatures {87.9, 77.9, 80.0, 72.5};
    double average_temp {};
    double total {};
   
    for (auto temp: temperatures)
        total += temp;
   
    if (temperatures.size() != 0)
        average_temp = total / temperatures.size();
    cout << fixed << setprecision(1);
    cout << "Average temperature is " << average_temp << endl;
        
    for (auto val: {1, 2, 3, 4, 5})
        cout << val << endl;

    for (auto c: "This is a test")
        cout << c;
    cout <<  endl;

    int res {};
    vector<int> vec {};
    if (!vec.empty())  // vec.size() returns unsigned int
    {
        for (int i {}; i < vec.size() - 1; i++)
        {
            for (int j {i + 1}; j < vec.size(); j++)
                res += vec.at(i) * vec.at(j);
        }
    }
    cout << res << endl;

    return 0;
}

