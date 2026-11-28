// Problem: High Card Low Card
// Contest: USACO December 2015 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=573

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> cards(2 * n, true);
    vector<int> highest_cards(n / 2);
    vector<int> lowest_cards(n / 2);

    for (int i = 0; i < n / 2; i++) {
        int card;

        cin >> card;

        cards[card - 1] = false;
        highest_cards[i] = card - 1;
    }

    for (int i = n / 2; i < n; i++) {
        int card;

        cin >> card;

        cards[card - 1] = false;
        lowest_cards[i - n / 2] = card - 1;
    }

    sort(highest_cards.begin(), highest_cards.end());
    sort(lowest_cards.begin(), lowest_cards.end());

    int wins = 0;
    int highest = 2 * n - 1;

    for (int i = 0; i < n / 2; i++) {
        while (not cards[highest]) {
            highest -= 1;
        }

        if (highest > highest_cards[n / 2 - i - 1]) {
            highest -= 1;
            wins += 1;
        }
    }

    int lowest = 0;

    for (int i = n / 2; i < n; i++) {
        while (not cards[lowest]) {
            lowest += 1;
        }

        if (lowest < lowest_cards[i - n / 2]) {
            lowest += 1;
            wins += 1;
        }
    }

    cout << wins;

    return 0;
}
