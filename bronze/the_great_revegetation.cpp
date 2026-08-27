// Problem: The Great Revegetation
// Contest: USACO February 2019 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=916

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n));

    for (int i = 0; i < m; i++) {
        int p1, p2;

        cin >> p1 >> p2;

        graph[p1 - 1][p2 - 1] = true;
        graph[p2 - 1][p1 - 1] = true;
    }

    vector<int> grains(n);

    for (int i = 0; i < n; i++) {
        grains[i] = 0;
    }

    vector<bool> available(4);

    for (int i = 0; i < 4; i++) {
        available[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        vector<bool> availabilities = available;

        for (int k = 0; k < n; k++) {
            if (graph[i][k] and grains[k] != 0) {
                availabilities[grains[k] - 1] = true;
            }
        }

        for (int j = 0; j < 4; j++) {
            if (availabilities[j] == false) {
                grains[i] = j + 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << grains[i];
    }

    return 0;
}
