// Problem: Farmer John's Cheese Block
// Contest: USACO December 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1444

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;

    cin >> n >> q;

    vector<vector<int>> rows(n, vector<int>(n, n));
    vector<vector<int>> cols(n, vector<int>(n, n));
    vector<vector<int>> height(n, vector<int>(n, n));

    int finished = 0;

    for (int i = 0; i < q; i++) {
        int x, y, z;

        cin >> x >> y >> z;

        rows[x][z] -= 1;
        cols[y][z] -= 1;
        height[x][y] -= 1;

        if (rows[x][z] == 0) {
            finished += 1;
        }

        if (cols[y][z] == 0) {
            finished += 1;
        }

        if (height[x][y] == 0) {
            finished += 1;
        }

        cout << finished << endl;
    }

    return 0;
}
