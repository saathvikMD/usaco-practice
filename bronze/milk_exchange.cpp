// Problem: Milk Exchange
// Contest: USACO February 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1396

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    string direction;

    cin >> direction;

    vector<int> capacity(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> capacity[i];
        sum += capacity[i];
    }

    vector<int> change(n);

    if (capacity[0] >= 1) {
        change[0] -= 1;

        if (direction[0] == 'L') {
            change[n - 1] += 1;
        } else {
            change[1] += 1;
        }
    }

    for (int i = 1; i < n - 1; i++) {
        if (capacity[i] >= 1) {
            change[i] -= 1;

            if (direction[i] == 'L') {
                change[i - 1] += 1;
            } else {
                change[i + 1] += 1;
            }
        }
    }

    if (capacity[n - 1] >= 1) {
        change[n - 1] -= 1;

        if (direction[n - 1] == 'L') {
            change[n - 2] += 1;
        } else {
            change[0] += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        int chain = 0;
        int index = i;

        while (chain < m and change[index] < 0) {
            change[index] = 0;

            if (capacity[index] <= m - chain) {
                chain += capacity[index];
            } else {
                chain += m - chain;
            }

            if (chain == m) {
                break;
            }

            if (direction[index] == 'L') {
                index -= 1;

                if (index == -1) {
                    index = n - 1;
                }
            } else {
                index += 1;

                if (index == n) {
                    index = 0;
                }
            }

            change[index] -= 1;
        }

        sum -= chain;
    }

    cout << sum << endl;

    return 0;
}
