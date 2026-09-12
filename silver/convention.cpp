// Problem: Convention
// Contest: USACO December 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=858

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> arrivals, int n, int m, int c, int max_wait) {
    int buses_used = 0;
    int tickets_remaining = c;
    int start_time = 0;

    for (int i = 0; i < n; i++) {
        if (tickets_remaining == c or tickets_remaining == 0) {
            start_time = arrivals[i];
            tickets_remaining = c - 1;
            buses_used += 1;
        } else {
            if (arrivals[i] - start_time > max_wait) {
                tickets_remaining = c - 1;
                buses_used += 1;
                start_time = arrivals[i];
            } else {
                tickets_remaining -= 1;
            }
        }

        if (buses_used > m) {
            return false;
        }
    }

    return true;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int n, m, c;

    cin >> n >> m >> c;

    vector<int> arrivals(n);

    for (int i = 0; i < n; i++) {
        cin >> arrivals[i];
    }

    sort(arrivals.begin(), arrivals.end());

    int low = 0;
    int high = arrivals[n - 1] - arrivals[0];
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(arrivals, n, m, c, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer;

    return 0;
}
