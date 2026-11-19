// Problem: Closest Cow Wins
// Contest: USACO December 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1158

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m, n;

    cin >> k >> m >> n;

    vector<pair<int, int>> patches(k);

    for (int i = 0; i < k; i++) {
        cin >> patches[i].first >> patches[i].second;
    }

    vector<int> cows(m);

    for (int i = 0; i < m; i++) {
        cin >> cows[i];
    }

    sort(patches.begin(), patches.end());
    sort(cows.begin(), cows.end());

    vector<pair<int, int>> nearest(k);
    int cow = 0;

    for (int i = 0; i < k; i++) {
        while (cow < m and cows[cow] < patches[i].first) {
            cow += 1;
        }

        if (cow == 0) {
            nearest[i] = {-1, 0};
        } else if (cow == m) {
            nearest[i] = {m - 1, -1};
        } else {
            nearest[i] = {cow - 1, cow};
        }
    }

    priority_queue<long long> pq;
    long long sum = 0;
    int index = 0;
    int left, right;

    while (nearest[index].first == -1) {
        sum += patches[index].second;
        index += 1;
    }

    left = index;
    pq.push(sum);

    sum = 0;
    index = k - 1;

    while (nearest[index].second == -1) {
        sum += patches[index].second;
        index -= 1;
    }

    right = index;
    pq.push(sum);

    if (left <= right) {
        int start = left;
        int end = left;
        sum = patches[start].second;
        long long max_sum = sum;
        long long interval_sum = sum;

        while (end < right) {
            if (nearest[end] == nearest[end + 1]) {
                if (abs(patches[start].first + min(patches[start].first - cows[nearest[start].first], cows[nearest[start].second] - patches[start].first) - 0.5 - patches[end + 1].first) < min(patches[end + 1].first - cows[nearest[end + 1].first], cows[nearest[end + 1].second] - patches[end + 1].first)) {
                    end += 1;
                    sum += patches[end].second;
                    interval_sum += patches[end].second;
                    max_sum = max(max_sum, sum);
                } else {
                    start += 1;
                    sum -= patches[start - 1].second;
                }
            } else {
                pq.push(max_sum);
                pq.push(interval_sum - max_sum);
                start = end + 1;
                end = end + 1;
                sum = patches[start].second;
                max_sum = sum;
                interval_sum = sum;
            }
        }

        pq.push(max_sum);
        pq.push(interval_sum - max_sum);
    }

    long long total = 0;

    for (int i = 0; i < n and not pq.empty(); i++) {
        total += pq.top();
        pq.pop();
    }

    cout << total;

    return 0;
}
