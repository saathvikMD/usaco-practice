// Problem: The Great Revegetation
// Contest: USACO February 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=920

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout); 

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, char>>> connections(n);

    for (int i = 0; i < m; i++) {
        char type;
        int p1, p2;

        cin >> type >> p1 >> p2;

        connections[p1 - 1].push_back({p2 - 1, type});
        connections[p2 - 1].push_back({p1 - 1, type});
    }

    vector<int> visited(n, 0);

    int count = 0;
    bool possible = true;

    for (int i = 0; i < n and possible; i++) {
        if (visited[i] == 0) {
            count += 1;
            visited[i] = 1;

            queue<int> q;

            q.push(i);

            while (q.size() > 0) {
                int x = q.front();
                q.pop();

                for (int j = 0; j < connections[x].size(); j++) {
                    if (visited[connections[x][j].first] == 0) {
                        visited[connections[x][j].first] = (connections[x][j].second == 'S' ? 1 : -1) * visited[x];
                        q.push(connections[x][j].first);
                    } else if ((connections[x][j].second == 'S' ? 1 : -1) * visited[x] != visited[connections[x][j].first]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
    }

    if (possible) {
        cout << "1";

        for (int i = 0; i < count; i++) {
            cout << "0";
        }
    } else {
        cout << "0";
    }

    return 0;
}
