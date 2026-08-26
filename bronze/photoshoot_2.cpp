// Problem: Photoshoot 2
// Contest: USACO February 2022 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1204

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> cows(n);
    vector<int> location(n);
    vector<int> expected(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
        location[cows[i] - 1] = cows[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> expected[i];
    }

    int modifications = 0;
    int pointer = 0;
    int index = 0;

    while (index < n) {
        if (cows[pointer] != expected[index]) {
            if (location[cows[pointer] - 1] != 0) {
                location[expected[index] - 1] = 0;
                index += 1;
                modifications += 1;
            } else {
                pointer += 1;
            }
        } else {
            pointer += 1;
            index += 1;
        }
    }

    cout << modifications;

    return 0;
}
