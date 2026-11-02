// Problem: Milk Visits
// Contest: USACO December 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=968

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    string breed;

    cin >> breed;

    vector<vector<int>> roads(n, vector<int>());

    for (int i = 0; i < n - 1; i++) {
        int x, y;

        cin >> x >> y;

        roads[x - 1].push_back(y - 1);
        roads[y - 1].push_back(x - 1);
    }

    vector<int> cows(n, -1);
    int component = 0;

    for (int i = 0; i < n; i++) {
        if (cows[i] == -1) {
            queue<int> q;
            q.push(i);
            cows[i] = component;

            while (not q.empty()) {
                int x = q.front();
                q.pop();

                for (int j = 0; j < roads[x].size(); j++) {
                    int y = roads[x][j];

                    if (cows[y] == -1 and breed[x] == breed[y]) {
                        cows[y] = component;
                        q.push(y);
                    }
                }
            }

            component += 1;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        char c;

        cin >> a >> b >> c;

        a -= 1;
        b -= 1;

        if (cows[a] == cows[b] and breed[a] == c) {
            cout << 1;
        } else if (cows[a] == cows[b]) {
            cout << 0;
        }  else {
            cout << 1;
        }
    }

    return 0;
}
