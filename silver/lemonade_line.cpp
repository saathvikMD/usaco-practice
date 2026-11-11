// Problem: Lemonade Line
// Contest: USACO 2018 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=835

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    int front = 0;
    int end = n - 1;
    int line = 0;

    while (front <= end) {
        if (line > cows[front]) {
            front += 1;
        } else {
            end -= 1;
            line += 1;
        }
    }

    cout << line;

    return 0;
}
