// Problem: Walking Home
// Contest: USACO December 2021 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1157

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        vector<vector<vector<pair<bool, int>>>> paths(n + 1, vector<vector<pair<bool, int>>>(n + 1));

        paths[0][0].push_back({true, 0});
        paths[0][0].push_back({false, 0});

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '.') {
                    for (int o = 0; o < paths[x][y].size(); o++) {
                        bool direction = paths[x][y][o].first;
                        int turns = paths[x][y][o].second;

                        if (direction) {
                            paths[x + 1][y].push_back({direction, turns});

                            if (turns < k and x + y > 0) {
                                paths[x][y + 1].push_back({not direction, turns + 1});
                            }
                        } else {
                            paths[x][y + 1].push_back({direction, turns});

                            if (turns < k and x + y > 0) {
                                paths[x + 1][y].push_back({not direction, turns + 1});
                            }
                        }
                    }
                }
            }
        }

        cout << paths[n - 1][n - 1].size() << "\n";
    }

    return 0;
}
