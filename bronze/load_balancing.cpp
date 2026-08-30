// Problem: Load Balancing
// Contest: USACO February 2016 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=617

#include <bits/stdc++.h>
using namespace std;

int group_count(int midx, int midy, vector<pair<int,int>> cows) {
    vector<int> quadrant(4, 0);

    for (int i = 0; i < cows.size(); i++) {
        if (cows[i].first > midx) {
            if (cows[i].second > midy) {
                quadrant[0] += 1;
            } else {
                quadrant[3] += 1;
            }
        } else {
            if (cows[i].second > midy) {
                quadrant[1] += 1;
            } else {
                quadrant[2] += 1;
            }
        }
    }

    return max({quadrant[0], quadrant[1], quadrant[2], quadrant[3]});
}

int main() {
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;

    cin >> n >> b;

    vector<pair<int,int>> cows(n);
    vector<int> x(n);
    vector<int> y(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        x[i] = cows[i].first;
        y[i] = cows[i].second;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int min_groups_count = INT_MAX;
    int prev_x = -1;

    for (int i = 0; i < n; i++) {
        if (x[i] != prev_x) {
            int prev_y = -1;

            for (int j = 0; j < n; j++) {
                if (y[j] != prev_y) {
                    int gc = group_count(x[i] + 1, y[j] + 1, cows);

                    if (gc < min_groups_count) {
                        min_groups_count = gc;
                    }

                    prev_y = y[j];
                }
            }

            prev_x = x[i];
        }
    }

    cout << min_groups_count;

    return 0;
}
