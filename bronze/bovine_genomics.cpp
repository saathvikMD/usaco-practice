// Problem: Bovine Genomics
// Contest: USACO 2017 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;

    cin >> n >> m;

    vector<string> genomes(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> genomes[i];
    }

    bool match = false;
    int count = 0;

    for (int i = 0; i < m; i++) {
        match = false;

        for (int j = 0; j < n and not match; j++) {
            for (int k = n; k < n * 2 and not match; k++) {
                if (genomes[j][i] == genomes[k][i]) {
                    match = true;
                }
            }
        }

        if (not match) {
            count++;
        }
    }

    cout << count;

    return 0;
}
