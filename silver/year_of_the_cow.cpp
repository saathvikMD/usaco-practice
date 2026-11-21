// Problem: Year of the Cow
// Contest: USACO February 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1111

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end(), greater<int>());

    int total = cows[0] + 12 - cows[0] % 12;
    int prev_visited = total;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        int distance = cows[i] + 12 - (cows[i] % 12);

        if (cows[i] - (cows[i] % 12) < prev_visited) {
            pq.push(prev_visited - distance);

            prev_visited = cows[i] - (cows[i] % 12);
        }
    }

    pq.push(prev_visited);

    while (k > 1 and not pq.empty()) {
        total -= pq.top();
        pq.pop();

        k -= 1;
    }

    cout << total;

    return 0;
}
