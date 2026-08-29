// Problem: Blocked Billboard
// Contest: USACO December 2017 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=759

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int b1x1, b1y1, b1x2, b1y2;
    int b2x1, b2y1, b2x2, b2y2;
    int tx1, ty1, tx2, ty2;

    cin >> b1x1 >> b1y1 >> b1x2 >> b1y2;
    cin >> b2x1 >> b2y1 >> b2x2 >> b2y2;
    cin >> tx1 >> ty1 >> tx2 >> ty2;

    int area1, area2;

    area1 = (b1x2 - b1x1) * (b1y2 - b1y1);
    area2 = (b2x2 - b2x1) * (b2y2 - b2y1);

    int tempx1, tempy1, tempx2, tempy2;

    tempx1 = max(tx1, b1x1);
    tempy1 = max(ty1, b1y1);
    tempx2 = min(tx2, b1x2);
    tempy2 = min(ty2, b1y2);

    area1 -= max(0, (tempx2 - tempx1)) * max(0, (tempy2 - tempy1));

    tempx1 = max(tx1, b2x1);
    tempy1 = max(ty1, b2y1);
    tempx2 = min(tx2, b2x2);
    tempy2 = min(ty2, b2y2);

    area2 -= max(0, (tempx2 - tempx1)) * max(0, (tempy2 - tempy1));

    cout << area1 + area2;

    return 0;
}
