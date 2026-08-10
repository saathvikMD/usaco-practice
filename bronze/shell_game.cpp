// Problem: Shell Game
// Contest: USACO January 2019 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=891

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    int maxval = 0;

    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    int location = 0;
    int currval = 0;
    int a = 0, b = 0, g = 0;

    for (int i = 0; i < 3; i++) {
        location = i + 1;
        currval = 0;

        for (int j = 0; j < n; j++) {
            a = matrix[j][0];
            b = matrix[j][1];
            g = matrix[j][2];
            
            if (a == location) {
                location = b;
            } else if (b == location) {
                location = a;
            }

            if (g == location) {
                currval += 1;
            }
        }

        if (currval > maxval) {
            maxval = currval;
        }
    }

    cout << maxval;

    return 0;
}
