// Problem: The Bovine Shuffle
// Contest: USACO December 2017 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=760

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;

    cin >> n;

    vector<int> order(n);
    vector<int> reverse_order(n);

    for (int i = 0; i < n; i++) {
        cin >> order[i];
        reverse_order[order[i] - 1] = i;
    }

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    vector<int> original_cows(n);

    for (int iteration = 0; iteration < 3; iteration++) {
        for (int i = 0; i < n; i++) {
            original_cows[reverse_order[i]] = cows[i];
        }

        cows = original_cows;
    }

    for (int i = 0; i < n; i++) {
        cout << cows[i] << "\n";
    }

    return 0;
}
