// Problem: High Card Wins
// Contest: USACO December 2015 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=571

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<bool> cards(n * 2, false);

    for (int i = 0; i < n; i++) {
        int card;

        cin >> card;

        cards[card - 1] = true;
    }

    int bessie = 0;
    int wins = 0;

    for (int i = n * 2 - 1; i >= 0; i--) {
        if (cards[i]) {
            if (bessie > 0) {
                wins += 1;
                bessie -= 1;
            }
        } else {
            bessie += 1;
        }
    }

    cout << wins;

    return 0;
}
