// Problem: Mixing Milk
// Contest: USACO December 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=855

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    int c1, m1, c2, m2, c3, m3;

    cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i = 0; i < 100; i++) {
        if (i % 3 == 2) {
            if (c1 <= m1 + m3) {
                m3 = m3 - (c1 - m1);
                m1 = c1;
            } else {
                m1 += m3;
                m3 = 0;
            }
        } else if (i % 3 == 1) {
            if (c3 <= m3 + m2) {
                m2 = m2 - (c3 - m3);
                m3 = c3;
            } else {
                m3 += m2;
                m2 = 0;
            }
        } else {
            if (c2 <= m2 + m1) {
                m1 = m1 - (c2 - m2);
                m2 = c2;
            } else {
                m2 += m1;
                m1 = 0;
            }
        }
    }

    cout << m1 << "\n" << m2 << "\n" << m3;

    return 0;
}


