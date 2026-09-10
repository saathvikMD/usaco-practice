// Problem: Stamp Grid
// Contest: USACO February 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1300

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;

        cin >> n;

        vector<string> painting(n);

        for (int i = 0; i < n; i++) {
            cin >> painting[i];
        }

        int k;

        cin >> k;

        vector<string> stamp(n);

        for (int i = 0; i < k; i++) {
            cin >> stamp[i];
        }

        vector<vector<char>> canvas(n, vector<char>(n, '.'));
        vector<vector<vector<char>>> rotations(4, vector<vector<char>>(k, vector<char>(k)));

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                rotations[0][i][j] = stamp[i][j];
                rotations[1][j][k - 1 - i] = stamp[i][j];
                rotations[2][k - 1 - i][k - 1 - j] = stamp[i][j];
                rotations[3][k - 1 - j][i] = stamp[i][j];
            }
        }

        for (int i = 0; i < n - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                for (int dir = 0; dir < 4; dir++) {
                    bool passed = true;

                    for (int o = 0; o < k and passed; o++) {
                        for (int l = 0; l < k and passed; l++) {
                            if (painting[i + o][j + l] == '.' and rotations[dir][o][l] == '*') {
                                passed = false;
                                break;
                            }
                        }
                    }

                    if (passed) {
                        for (int o = 0; o < k and passed; o++) {
                            for (int l = 0; l < k and passed; l++) {
                                if (rotations[dir][o][l] == '*') {
                                    canvas[i + o][j + l] = '*';
                                }
                            }
                        }
                    }
                }
            }
        }

        bool passed = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (canvas[i][j] != painting[i][j]) {
                    passed = false;
                    break;
                }
            }
        }

        if (passed) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
