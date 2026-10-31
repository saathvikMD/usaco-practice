// Problem: MooTube
// Contest: USACO January 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=788

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    vector<vector<pair<int, long long>>> relevance(n, vector<pair<int, long long>>());

    for (int i = 0; i < n - 1; i++) {
        int p, q;
        long long r;

        cin >> p >> q >> r;

        relevance[p - 1].push_back({q - 1, r});
        relevance[q - 1].push_back({p - 1, r});
    }

    for (int i = 0; i < q; i++) {
        long long k, v;

        cin >> k >> v;

        vector<bool> visited(n, false);

        queue<int> q;
        q.push(v - 1);
        visited[v - 1] = true;
        int count = 0;

        while (q.size() > 0) {
            int curr = q.front();
            q.pop();

            for (int j = 0; j < relevance[curr].size(); j++) {
                if (not visited[relevance[curr][j].first]) {
                    if (relevance[curr][j].second >= k) {
                        visited[relevance[curr][j].first] = true;
                        q.push(relevance[curr][j].first);
                        count += 1;
                    }
                }
            }
        }

        cout << count << "\n";
    }

    return 0;
}
