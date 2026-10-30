// Problem: Rental Service
// Contest: USACO January 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=787

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r;

    cin >> n >> m >> r;

    vector<int> cows(n);
    vector<pair<int, int>> milk(m);
    vector<int> rent(r);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    for (int i = 0; i < m; i++) {
        int g, p;

        cin >> g >> p;

        milk[i].first = p;
        milk[i].second = g;
    }

    for (int i = 0; i < r; i++) {
        cin >> rent[i];
    }

    sort(cows.begin(), cows.end(), greater<int>());
    sort(milk.begin(), milk.end(), greater<pair<int, int>>());
    sort(rent.begin(), rent.end(), greater<int>());

    vector<long long> generated(n);
    vector<pair<long long, long long>> selling(m + 1, {0, 0});
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += cows[i];
        generated[i] = sum;
    }

    long long profit = 0;
    long long sold = 0;

    for (int i = 0; i < m; i++) {
        sold += milk[i].second;
        profit += (long long) milk[i].first * milk[i].second;

        selling[i + 1] = {sold, profit};
    }

    long long max_profit = 0;
    long long rent_money = 0;
    sold = 0;

    for (int i = 0; i <= r and i <= n; i++) {
        long long gallons = (i == n ? 0 : generated[n - 1 - i]);
        rent_money += (i == 0 ? 0 : rent[i - 1]);

        while (selling[m - sold].first > gallons) {
            sold += 1;
        }

        if (sold == 0) {
            max_profit = max(max_profit, rent_money + selling[m - sold].second);
        } else {
            max_profit = max(max_profit, rent_money + selling[m - sold].second + (gallons - selling[m - sold].first) * milk[m - sold].first);
        }
    }

    cout << max_profit;

    return 0;
}
