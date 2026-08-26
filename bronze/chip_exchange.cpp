// Problem: Chip Exchange
// Contest: USACO 2026 First Contest Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1539

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;

    cin >> n;

    for (long long t = 0; t < n; t++) {
        long long a, b, ca, cb, fa;
        long long a_temp, b_temp;

        cin >> a >> b >> ca >> cb >> fa;

        if (b >= cb) {
            long long times = b / cb;

            b -= times * cb;
            a += times * ca;
        }

        a_temp = a, b_temp = b;

        if (a < fa) {
            if (cb < ca) {
                cout << fa - a + max((cb - b - 1), 0LL) << "\n";
            } else {
                long long chips1 = 0;
                
                long long times = (fa - a + ca - 1) / ca;

                a += ca * times;
                chips1 += cb * times;
                chips1 -= b;
                chips1 += max(0LL, fa - (a - ca) - 1);

                long long chips2 = 0;
                a = a_temp, b = b_temp;

                while (fa > a) {
                    if (cb - b > ca) {
                        if (b == 0) {
                            long long times = (fa - a + ca - 1) / ca;

                            a += times * ca;
                            chips2 += times * cb;
                        } else {
                            a += ca;
                            chips2 += cb - b;
                            b = 0;
                        }
                    } else {
                        chips2 += fa - a;
                        a += fa - a;
                        chips2 += max(cb - b - 1, 0LL);
                    }
                }

                cout << max(chips1, chips2) << "\n";
            }
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}
