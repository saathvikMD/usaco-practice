// Problem: Blocked Billboard II
// Contest: USACO January 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=783

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    if (bx1 <= ax1 and bx2 >= ax2 and by1 <= ay1 and by2 >= ay2) {
        cout << 0;
    } else if (bx1 <= ax1 and bx2 >= ax2 and by2 > ay1 and by1 <= ay1) {
        cout << (ax2 - ax1) * (ay2 - by2);
    } else if (bx1 <= ax1 and bx2 >= ax2 and by1 < ay2 and by2 >= ay2) {
        cout << (ax2 - ax1) * (by1 - ay1);
    } else if (by1 <= ay1 and by2 >= ay2 and bx2 >= ax2 and bx1 > ax1) {
        cout << (bx1 - ax1) * (ay2 - ay1);
    } else if (by1 <= ay1 and by2 >= ay2 and bx1 <= ax1 and bx2 < ax2) {
        cout << (ax2 - bx2) * (ay2 - ay1);
    } else {
        cout << (ax2 - ax1) * (ay2 - ay1);
    }
}
