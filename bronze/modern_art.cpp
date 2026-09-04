// Problem: Modern Art
// Contest: USACO US Open 2017 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=737

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;

    cin >> n;

    vector<string> painting(n);
    vector<vector<int>> rectangles(9, vector<int> {INT_MAX, 0, INT_MAX, 0, 0});

    for (int i = 0; i < n; i++) {
        cin >> painting[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cell = painting[i][j];
            if (cell != '0') {
                rectangles[cell - '0' - 1][0] = min(rectangles[cell - '0' - 1][0], j);
                rectangles[cell - '0' - 1][1] = max(rectangles[cell - '0' - 1][1], j);
                rectangles[cell - '0' - 1][2] = min(rectangles[cell - '0' - 1][2], i);
                rectangles[cell - '0' - 1][3] = max(rectangles[cell - '0' - 1][3], i);
                rectangles[cell - '0' - 1][4] = 1;
            }
        }
    }

    int colors = 0;

    for (int i = 0; i < 9; i++) {
        if (rectangles[i][4]) {
            colors++;
        }
    }

    if (colors == 1) {
        cout << 0;
        return 0;
    }

    int possibilities = 0;

    for (int i = 0; i < 9; i++) {
        bool covering = false;

        if (rectangles[i][4]) {
            for (int j = 0; j < 9 and not covering; j++) {
                if (j != i and rectangles[j][4]) {
                    for (int x = rectangles[j][2]; x <= rectangles[j][3]; x++) {
                        for (int y = rectangles[j][0]; y <= rectangles[j][1]; y++) {
                            if (painting[x][y] == i + '0' + 1) {
                                covering = true;
                            }
                        }
                    }
                }
            }

            if (not covering) {
                possibilities += 1;
            }
        }
    }

    cout << possibilities;

    return 0;
}
