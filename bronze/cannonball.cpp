// Problem: Cannonball
// Contest: USACO January 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1372

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;

    cin >> n >> s;

    vector<pair<int, int>> line(n);
    int total_targets = 0;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        if (x == 1) {
            total_targets += 1;
        }

        line[i].first = x;
        line[i].second = y;
    }

    bool direction = true;
    bool prev_zero = false;
    int power = 1;
    int broken = 0;
    s -= 1;

    if (total_targets > 0) {
        while (s >= 0 and s < n) {
            if (line[s].first == 1) {
                if (power >= line[s].second) {
                    broken += 1;
                    line[s].first = 2;

                    if (broken == total_targets) {
                        break;
                    }
                }
            } else if (line[s].first == 0) {
                if (line[s].second == 0) {
                    if (prev_zero) {
                        break;
                    }

                    prev_zero = true;
                } else {
                    prev_zero = false;
                }

                power += line[s].second;
                direction = not direction;
            }

            s += (power * (direction ? 1 : -1));
        }
    }

    cout << broken << "\n";

    return 0;
}
