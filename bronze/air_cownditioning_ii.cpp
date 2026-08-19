// Problem: Air Cownditioning II
// Contest: USACO January 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1276

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> cows(n, vector<int>(3));
    vector<vector<int>> ac(m, vector<int>(4));
    vector<int> stalls(100);

    for (int i = 0; i < n; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }

    for (int i = 0; i < m; i++) {
        cin >> ac[i][0] >> ac[i][1] >> ac[i][2] >> ac[i][3];
    }

    int cost, min_cost= INT_MAX;
    bool pass;

    for (int i = 0; i < (1 << m); i++) {
        for (int i = 0; i < 100; i++) {
            stalls[i] = 0;
        }

        cost = 0;

        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                for (int k = ac[j][0]; k <= ac[j][1]; k++) {
                    stalls[k - 1] += ac[j][2];
                }

                cost += ac[j][3];
            }
        }

        pass = true;

        for (int j = 0; j < n and pass; j++) {
            for (int k = cows[j][0]; k <= cows[j][1] and pass; k++) {
                if (stalls[k - 1] < cows[j][2]) {
                    pass = false;
                }
            }
        }

        if (pass) {
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
    }

    cout << min_cost;

    return 0;
}
