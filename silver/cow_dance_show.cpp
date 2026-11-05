// Problem: Cow Dance Show
// Contest: USACO January 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=690

#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int> &durations, int t, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++) {
        pq.push(durations[i]);
    }

    int cow = k;

    while (cow != durations.size()) {
        int leaving = pq.top();
        pq.pop();

        pq.push(leaving + durations[cow]);
        cow += 1;
    }

    int end = 0;

    while (not pq.empty()) {
        end = pq.top();
        pq.pop();
    }

    return end <= t;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;

    cin >> n >> t;

    vector<int> durations(n);

    for (int i = 0; i < n; i++) {
        cin >> durations[i];
    }

    int low = 1;
    int high = n;
    int answer = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(durations, t, mid)) {
            answer = min(answer, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
