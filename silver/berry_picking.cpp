// Problem: Berry Picking
// Contest: USACO January 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=990

#include <bits/stdc++.h>
using namespace std;

int threshold(vector<int> berries, int limit, int k) {
    int index = 1000;
    int bessie = 0;

    for (int i = 0; i < k; i++) {
        while (true) {
            if (berries[index] > 0) {
                if (index > limit) {
                    berries[index] -= 1;
                    berries[index - limit] += 1;

                    if (i >= k/2) {
                        bessie += limit;
                    }
                } else {
                    berries[index] -= 1;

                    if (i >= k/2) {
                        bessie += index;
                    }
                }

                break;
            } else {
                index -= 1;
            }
        }
    }

    return bessie;
}

int main() {
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> berries(1001, 0);
    berries[0] = 1000;

    for (int i = 0; i < n; i++) {
        int b;

        cin >> b;

        berries[b] += 1;
    }

    int max_bessie = 0;

    for (int i = 1; i <= 1000; i++) {
        max_bessie = max(max_bessie, threshold(berries, i, k));
    }

    cout << max_bessie;

    return 0;
}
