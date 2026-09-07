// Problem: Angry Cows
// Contest: USACO January 2016 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=592

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;

    cin >> n;

    vector<int> bales(n);

    for (int i = 0; i < n; i++) {
        cin >> bales[i];
    }

    sort(bales.begin(), bales.end());
    int max_exploded = 0;

    for (int i = 0; i < n; i++) {
        int index = i - 1;
        int prev_position = bales[i];
        int exploded = 1;
        int explosion_range = 1;
        int next_bale = -1;

        while (index >= 0) {
            if (prev_position - bales[index] <= explosion_range) {
                next_bale = index;
                exploded += 1;
            } else {
                if (next_bale != -1) {
                    index = next_bale;
                    prev_position = bales[next_bale];
                    explosion_range += 1;
                    next_bale = -1;
                } else {
                    break;
                }
            }

            index -= 1;
        }

        index = i + 1;
        prev_position = bales[i];
        explosion_range = 1;
        next_bale = -1;

        while (index < n) {
            if (bales[index] - prev_position <= explosion_range) {
                next_bale = index;
                exploded += 1;
            } else {
                if (next_bale != -1) {
                    index = next_bale;
                    prev_position = bales[next_bale];
                    explosion_range += 1;
                    next_bale = -1;
                } else {
                    break;
                }
            }

            index += 1;
        }

        if (exploded > max_exploded) {
            max_exploded = exploded;
        }
    }

    cout << max_exploded;

    return 0;
}
