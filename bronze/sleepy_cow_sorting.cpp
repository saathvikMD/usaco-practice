// Problem: Sleepy Cow Sorting
// Contest: USACO January 2019 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=892

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;

    cin >> n;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int sorted_from_right = 0;
    bool done = false;

    for (int i = n - 1; i >= 1 and not done; i--) {
        if (cows[i] >= cows[i - 1]) {
            sorted_from_right += 1;
        } else {
            done = true;
        }
    }

    cout << n - sorted_from_right - 1;

    return 0;
}
