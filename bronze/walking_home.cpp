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

        vector<vector<vector<vector<int>>>> paths(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0))));

        paths[0][0][0][0] = 1;
        paths[0][0][0][1] = 1;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '.') {
                    for (int turns = 0; turns < k + 1; turns++) {
                        for (int direction = 0; direction < 2; direction++) {
                            if (direction) {
                                paths[x + 1][y][turns][direction] += paths[x][y][turns][direction];

                                if (turns < k and x + y > 0) {
                                    paths[x][y + 1][turns + 1][not direction] += paths[x][y][turns][direction];
                                }
                            } else {
                                paths[x][y + 1][turns][direction] += paths[x][y][turns][direction];

                                if (turns < k and x + y > 0) {
                                    paths[x + 1][y][turns + 1][not direction] += paths[x][y][turns][direction];
                                }
                            }
                        }
                    }
                }
            }
        }

        int diff_paths = 0;

        for (int i = 0; i < k + 1; i++) {
            for (int j = 0; j < 2; j++) {
                diff_paths += paths[n - 1][n - 1][i][j];
            }
        }

        cout << diff_paths << "\n";
    }

    return 0;
}
