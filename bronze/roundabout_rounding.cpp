// Problem: Roundabout Rounding
// Contest: USACO December 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1443

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;

    cin >> n;

    for (long long iteration = 0; iteration < n; iteration++) {
        long long number;

        cin >> number;

        long long differences = 0;
        long long i = 0;

        while (i <= number) {
            string n_string = to_string(i);
            i = 0;

            for (long long j = n_string.length(); j >= 0; j--) {
                i += 4 * pow(10, j);
            }

            i += 1;

            long long t = 5 * pow(10, n_string.length());
            differences += max(0LL, min(number + 1, t) - i);

            i = t;
        }

        cout << differences << endl;
    }

    return 0;
}
