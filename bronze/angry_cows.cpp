// Problem: Angry Cows
// Contest: USACO January 2016 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=592

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;

    cin >> n;

    vector<long long> positions(n);

    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    sort(positions.begin(), positions.end());

    int most_explosions = 0;

    for (int i = 0; i < n; i++) {
        vector<long long> exploding;
        vector<long long> exploded;

        long long iteration = 1;

        exploding.push_back(positions[i]);

        while (exploding.size() > 0) {
            for (int j = exploding.size() - 1; j >= 0; j--) {
                long long exploding_bale = exploding[j];

                exploding.erase(exploding.begin() + j);
                exploded.push_back(exploding_bale);

                for (int k = 0; k < n; k++) {
                    if (abs(positions[k] - exploding_bale) <= iteration) {
                        if (find(exploded.begin(), exploded.end(), positions[k]) == exploded.end() and find(exploding.begin(), exploding.end(), positions[k]) == exploding.end()) {
                            exploding.push_back(positions[k]);
                        }
                    }
                }
            }

            iteration += 1;
        }

        most_explosions = max(most_explosions, (int) exploded.size());
    }

    cout << most_explosions;

    return 0;
}
