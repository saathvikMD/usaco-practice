// Problem: Connecting Two Barns
// Contest: USACO December 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1159

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, m;

        cin >> n >> m;

        vector<vector<int>> graph(n, vector<int>());

        for (int i = 0; i < m; i++) {
            int a, b;

            cin >> a >> b;

            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }

        vector<int> visited(n, -1);
        queue<int> q;
        q.push(0);
        visited[0] = 0;
        vector<int> starting;
        starting.push_back(-2 * n);
        starting.push_back(3 * n);
        starting.push_back(0);

        while (not q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < graph[x].size(); i++) {
                if (visited[graph[x][i]] == -1) {
                    visited[graph[x][i]] = 0;
                    q.push(graph[x][i]);
                    starting.push_back(graph[x][i]);
                }
            }
        }

        if (visited[n - 1] == 0) {
            cout << 0 << "\n";
            continue;
        }

        q.push(n - 1);
        visited[n - 1] = n - 1;
        vector<int> ending;
        ending.push_back(-2 * n);
        ending.push_back(3 * n);
        ending.push_back(n - 1);

        while (not q.empty()) {
            int x = q.front();
            q.pop();

            for (int i = 0; i < graph[x].size(); i++) {
                if (visited[graph[x][i]] == -1) {
                    visited[graph[x][i]] = n - 1;
                    q.push(graph[x][i]);
                    ending.push_back(graph[x][i]);
                }
            }
        }

        sort(starting.begin(), starting.end());
        sort(ending.begin(), ending.end());

        vector<long long> start_distance(n);
        vector<long long> end_distance(n);
        int curr_start_point = 1;
        int curr_end_point = 1;

        for (int i = 0; i < n; i++) {
            while (curr_start_point + 1 < starting.size() and abs(starting[curr_start_point + 1] - i) < abs(starting[curr_start_point] - i)) {
                curr_start_point += 1;
            }

            while (curr_end_point + 1 < ending.size() and abs(ending[curr_end_point + 1] - i) < abs(ending[curr_end_point] - i)) {
                curr_end_point += 1;
            }

            start_distance[i] = 1LL * (i - starting[curr_start_point]) * (i - starting[curr_start_point]);
            end_distance[i] = 1LL * (i - ending[curr_end_point]) * (i - ending[curr_end_point]);
        }

        long long min_distance = LLONG_MAX;

        for (int i = 1; i < starting.size() - 1; i++) {
            min_distance = min(min_distance, end_distance[starting[i]]);
        }

        for (int i = 1; i < ending.size() - 2; i++) {
            min_distance = min(min_distance, start_distance[ending[i]]);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                queue<int> q;
                q.push(i);
                visited[i] = i;
                long long min_start = start_distance[i];
                long long min_end = end_distance[i];

                while (not q.empty()) {
                    int x = q.front();
                    q.pop();

                    for (int i = 0; i < graph[x].size(); i++) {
                        if (visited[graph[x][i]] == -1) {
                            visited[graph[x][i]] = i;
                            q.push(graph[x][i]);

                            min_start = min(min_start, start_distance[graph[x][i]]);
                            min_end = min(min_end, end_distance[graph[x][i]]);
                        }
                    }
                }

                min_distance = min(min_distance, min_start + min_end);
            }
        }

        cout << min_distance << "\n";
    }

    return 0;
}
