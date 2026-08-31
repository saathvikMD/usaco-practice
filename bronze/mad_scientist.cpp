// Problem: Mad Scientist
// Contest: USACO February 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1012

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;

    cin >> n;

    string a;
    string b;

    cin >> a >> b;

    bool can_be_flipped = false;
    int total_count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            can_be_flipped = true;
        } else if (can_be_flipped) {
            total_count += 1;
            can_be_flipped = false;
        }
    }

    if (can_be_flipped) {
        total_count += 1;
    }

    cout << total_count;

    return 0;
}
