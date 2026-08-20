// Problem: Cow College
// Contest: USACO December 2022 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1251

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;

    cin >> n;

    vector<long long> max_tuition(n);

    for (long long i = 0; i < n; i++) {
        cin >> max_tuition[i];
    }

    sort(max_tuition.begin(), max_tuition.end());

    long long current = max_tuition[n - 1], optimal = 0, tuition = 0;

    for (long long i = n - 1; i >= 0; i--) {
        if (max_tuition[i] < current) {
            if ((n - i - 1) * current >= optimal) {
                optimal = (n - i - 1) * current;
                tuition = current;
            }

            current = max_tuition[i];
        }
    }

    if (max_tuition[0] * n >= optimal) {
        optimal = max_tuition[0] * n;
        tuition = max_tuition[0];
    }

    cout << optimal << " " << tuition;

    return 0;
}
