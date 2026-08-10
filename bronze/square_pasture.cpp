// Problem: Square Pasture
// Contest: USACO December 2016 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=663

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);

    int a_x1, a_y1, a_x2, a_y2;
    cin >> a_x1 >> a_y1 >> a_x2 >> a_y2;

    int b_x1, b_y1, b_x2, b_y2;
    cin >> b_x1 >> b_y1 >> b_x2 >> b_y2;

    int min_x = max(a_x2, b_x2) - min(a_x1, b_x1);
    int min_y = max(a_y2, b_y2) - min(a_y1, b_y1);

    int max_val = max(min_x, min_y);

    cout << max_val * max_val;

    return 0;
}
