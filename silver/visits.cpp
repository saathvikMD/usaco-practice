// Problem: Visits
// Contest: USACO 2022 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1230

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> in(n);
    vector<pair<int, int>> buddy(n);

    for (int i = 0; i < n; i++) {
        int a, v;

        cin >> a >> v;

        a -= 1;

        buddy[i] = {a, v};
        in[a] += 1;
    }

    long long total = 0;
    vector<int> visited(n);

    for (int i = 0; i < n; i++) {
        int curr =  i;

        while (in[curr] == 0 and not visited[curr]) {
            in[buddy[curr].first] -= 1;
            total += buddy[curr].second;

            visited[curr] = true;
            curr = buddy[curr].first;
        }
    }

    for (int i = 0; i < n; i++) {
        if (not visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int minimum = INT_MAX;

            while (not q.empty()) {
                int curr = q.front();
                minimum = min(minimum, buddy[curr].second);
                total += buddy[curr].second;
                q.pop();

                if (not visited[buddy[curr].first]) {
                    q.push(buddy[curr].first);
                    visited[buddy[curr].first] = true;
                }
            }

            total -= minimum;
        }
    }

    cout << total;

    return 0;
}
