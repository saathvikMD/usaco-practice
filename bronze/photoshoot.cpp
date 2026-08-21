// Problem: Photoshoot
// Contest: USACO January 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=988

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int n;

    cin >> n;

    vector<bool> used(n);
    vector<int> sums(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> sums[i];
    }

    int prev_value, curr_value;
    bool done = false;

    for (int i = 1; i <= n and not done; i++) {
        prev_value = i;

        for (int j = 0; j < n; j++) {
            used[j] = false;
        }

        used[prev_value - 1] = true;

        for (int j = 1; j < n and not done; j++) {
            curr_value = sums[j - 1] - prev_value;

            if (curr_value > 0 and curr_value <= n) {
                if (used[curr_value - 1] == true) {
                    done = true;
                }
              
                used[curr_value - 1] = true;
                prev_value = curr_value;
            } else {
                done = true;
            }
        }

        done = not done;

        if (done) {
            prev_value = i;
        }
    }

    for (int j = 1; j < n; j++) {
        cout << prev_value << " ";
        curr_value = sums[j - 1] - prev_value;
        prev_value = curr_value;
    }

    cout << prev_value;

    return 0;
}
