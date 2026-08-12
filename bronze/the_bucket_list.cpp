// Problem: The Bucket List
// Contest: USACO December 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=856

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;

    cin >> n;

    int matrix[n][3];

    int max_x = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][1] > max_x) {
            max_x = matrix[i][1];
        }
    }

    int buckets = 0;
    int curr;

    for (int i = 0; i < max_x - 1; i++) {
        curr = 0;

        for (int j = 0; j < n; j++) {
            if (matrix[j][0] <= (i + 1) and matrix[j][1] >= (i + 1)) {
                curr += matrix[j][2];
            }
        }

        if (curr > buckets) {
            buckets = curr;
        }
    }

    cout << buckets;

    return 0;
}
