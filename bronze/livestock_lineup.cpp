// Problem: Livestock Lineup
// Contest: USACO December 2019 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=965

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;

    cin >> n;

    vector<string> names = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(names.begin(), names.end());

    vector<vector<string>> rules(n, vector<string>(2));

    string trash;

    for (int i = 0; i < n; i++) {
        cin >> rules[i][0];

        cin >> trash;
        cin >> trash;
        cin >> trash;
        cin >> trash;

        cin >> rules[i][1];
    }

    bool pass = true;

    do {
        pass = true;

        for (int i = 0; i < n and pass; i++) {
            auto position1 = find(names.begin(), names.end(), rules[i][0]);
            auto position2 = find(names.begin(), names.end(), rules[i][1]);

            if (abs(position1 - position2) != 1) {
                pass = false;
            }
        }

        if (pass) {
            for (int i = 0; i < names.size(); i++) {
                cout << names[i] << "\n";
            }
        }

    } while (next_permutation(names.begin(), names.end()) and not pass);
}
