// Problem: Candy Cane Feast
// Contest: USACO December 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1347

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    long long cows[n];
    long long canes[m];

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> canes[i];
    }

    long long cane, eaten, temp;

    for (int i = 0; i < m; i++) {
        cane = canes[i];
        eaten = 0;

        for (int j = 0; j < n; j++) {
            if (cane - eaten == 0) {
                break;
            } else if (cows[j] > eaten) {
                temp = min(cows[j] - eaten, cane - eaten);
                eaten += temp;
                cows[j] += temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cows[i] << "\n";
    }

    return 0;
}
