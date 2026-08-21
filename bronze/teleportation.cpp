// Problem: Teleportation
// Contest: USACO February 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=807

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;

    cin >> a >> b >> x >> y;

    int tractor = abs(a - b);
    int teleport = abs(a - x) + abs(y - b);
    int teleport2 = abs(a - y) + abs(x - b);

    cout << min({tractor, teleport, teleport2});

    return 0;
}
