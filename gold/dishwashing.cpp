// Problem: Dishwashing
// Contest: USACO February 2019 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=922

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> stacks(n, vector<int>());
    int first = 0;
    int largest_washed = -1;
    int washed = 0;

    for (int i = 0; i < n; i++) {
        int dish;

        cin >> dish;

        if (dish < largest_washed) {
            break;
        }

        for (int j = first; j < n; j++) {
            if (stacks[j].empty()) {
                stacks[j].push_back(dish);

                break;
            } else if (dish < stacks[j][0]) {
                while (not stacks[j].empty() and dish > stacks[j].back()) {
                    washed += 1;
                    largest_washed = max(largest_washed, stacks[j].back());
                    stacks[j].pop_back();
                }

                stacks[j].push_back(dish);

                break;
            }
        }
    }

    for (int i = first; i < n; i++) {
        if (stacks[i].empty()) {
            break;
        } else {
            washed += stacks[i].size();
        }
    }

    cout << washed;

    return 0;
}
