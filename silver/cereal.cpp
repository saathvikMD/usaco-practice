// Problem: Cereal
// Contest: USACO 2020 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1039

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> cows(n);

    for (int i = 0; i < n; i++) {
        int f, s;

        cin >> f >> s;

        cows[i].first = f - 1;
        cows[i].second = s - 1;
    }

    vector<int> cereal(m, INT_MAX);
    vector<int> full(n);
    int ate = 0;

    for (int i = n - 1; i >= 0; i--) {
        queue<int> q;
        q.push(i);

        while (not q.empty()) {
            int first = cows[q.front()].first;
            int second = cows[q.front()].second;
            int cow = q.front();
            q.pop();

            if (cereal[first] == INT_MAX) {
                cereal[first] = cow;
                ate += 1;
            } else if (cereal[first] > cow) {
                q.push(cereal[first]);
                cereal[first] = cow;
            } else if (cereal[second] == INT_MAX) {
                cereal[second] = cow;
                ate += 1;
            } else if (cereal[second] > cow) {
                q.push(cereal[second]);
                cereal[second] = cow;
            }
        }

        full[i] = ate;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "\n";
        }

        cout << full[i];
    }

    return 0;
}
