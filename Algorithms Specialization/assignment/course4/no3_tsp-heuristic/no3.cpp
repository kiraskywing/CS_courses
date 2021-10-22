#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    double cities_x[n], cities_y[n];
    for (int i = 0, j; i < n; i++)
        cin >> j >> cities_x[i] >> cities_y[i];
    
    vector<bool> visited(n, false);
    int cur_i = 0, nxt_i;
    double res = 0, cur_dist, x_diff, y_diff, temp_dist;
    visited[0] = true;
    
    for (int times = 0; times < n - 1; times++) {
        cur_dist = INT_MAX;
        for (int i = cur_i + 1; i < n; i++) {
            if (visited[i])
                continue;
            x_diff = cities_x[i] - cities_x[cur_i];
            y_diff = cities_y[i] - cities_y[cur_i];
            if (x_diff > cur_dist)
                break;
            temp_dist = hypot(x_diff, y_diff);
            if (temp_dist < cur_dist) {
                cur_dist = temp_dist;
                nxt_i = i;
            }
        }
        for (int i = cur_i - 1; i >= 0; i--) {
            if (visited[i])
                continue;
            x_diff = cities_x[cur_i] - cities_x[i];
            y_diff = cities_y[cur_i] - cities_y[i];
            if (x_diff > cur_dist)
                break;
            temp_dist = hypot(x_diff, y_diff);
            if (temp_dist <= cur_dist) {
                cur_dist = temp_dist;
                nxt_i = i;
            }
        }
        // for (int i = n - 1; i > 0; i--) {
        //     if (visited[i])
        //         continue;
        //     x_diff = cities_x[cur_i] - cities_x[i];
        //     y_diff = cities_y[cur_i] - cities_y[i];
        //     temp_dist = hypot(x_diff, y_diff);
        //     if (temp_dist <= cur_dist) {
        //         cur_dist = temp_dist;
        //         nxt_i = i;
        //     }
        // }
        cur_i = nxt_i;
        visited[cur_i] = true;
        res += cur_dist;
    }

    res += hypot(cities_x[0] - cities_x[cur_i], cities_y[0] - cities_y[cur_i]);
    cout << fixed;
    cout.precision(2);
    cout << res << endl;
    
    return 0;
}