// Problem: Hoofball
// Contest: USACO February 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=808

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    
    if (n == 1) {
        cout << 1;
        
        return 0;
    }

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end());

    vector<vector<int>> edges(1001, vector<int>(1001, 0));

    edges[cows[1]][cows[0]] = 1;
    edges[cows[n - 2]][cows[n - 1]] = 1;

    int count = 0;

    for (int i = 1; i < n - 1; i++) {
        if (cows[i + 1] - cows[i] < cows[i] - cows[i - 1]) {
            edges[cows[i + 1]][cows[i]] = 1;
        } else {
        edges[cows[i - 1]][cows[i]] = 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int in = accumulate(edges[cows[i]].begin(), edges[cows[i]].end(), 0);
        if (in == 0) {
            count += 1;
        } else if (edges[cows[i]][cows[i + 1]] == 1 and edges[cows[i + 1]][cows[i]] == 1 and in == 1 and accumulate(edges[cows[i + 1]].begin(), edges[cows[i + 1]].end(), 0) == 1) {
            count += 1;
        }
    }

    if (accumulate(edges[cows[n - 1]].begin(), edges[cows[n - 1]].end(), 0) == 0) {
        count += 1;
    }

    cout << count;

    return 0;
}
