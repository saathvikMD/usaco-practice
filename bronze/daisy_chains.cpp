// Problem: Daisy Chains
// Contest: USACO December 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1060

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    int petals[n];

    for (int i = 0; i < n; i++) {
        cin >> petals[i];
    }

    int total, count, average;
    bool photo = false;
    int photos = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            total = 0;
            count = 0;
            photo = false;

            for (int k = i; k <= j; k++) {
                total += petals[k];
                count++;
            }

            if (total % count == 0) {
                average = total / count;

                for (int k = i; k <= j; k++) {
                    if (petals[k] == average) {
                        photo = true;
                        break;
                    }
                }

                if (photo) {
                    photos++;
                }
            }
        }
    }

    cout << photos;

    return 0;
}
