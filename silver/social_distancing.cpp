// Problem: Social Distancing
// Contest: USACO US Open 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1038

#include <bits/stdc++.h>
using namespace std;

bool possible(vector<pair<long long, long long>> grass, long long n, long long d) {
    long long cow_index = 0;
    long long grass_patch = 0;
    long long prev_position = -d;

    while (grass_patch < grass.size() and cow_index < n) {
        if (grass[grass_patch].second - prev_position >= d) {
            prev_position = max(grass[grass_patch].first, prev_position + d);
            cow_index += 1;
        } else {
            grass_patch += 1;
        }
    }

    if (cow_index == n) {
        return true;
    } else {
        return false;
    }
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;

    cin >> n >> m;

    vector<pair<long long, long long>> grass(m);

    for (long long i = 0; i < m; i++) {
        long long a, b;

        cin >> a >> b;

        grass[i].first = a;
        grass[i].second = b;
    }

    sort(grass.begin(), grass.end());

    long long low = 0;
    long long high = grass[m - 1].second;
    long long answer = LLONG_MIN;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (possible(grass, n, mid)) {
            answer = max(answer, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}
