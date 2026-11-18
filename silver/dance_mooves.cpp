// Problem: Dance Mooves
// Contest: USACO January 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1086

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> cows(n);
    vector<vector<int>> path(n, vector<int>());

    for (int i = 0; i < n; i++) {
        cows[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int a, b;

        cin >> a >> b;

        path[cows[a - 1]].push_back(b - 1);
        path[cows[b - 1]].push_back(a - 1);

        int temp = cows[a - 1];
        cows[a - 1] = cows[b - 1];
        cows[b - 1] = temp;
    }

    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (path[i].size() == 0) {
                visited[i] = 1;
            } else {
                vector<int> cycle;
                cycle.push_back(i);
                int curr = path[i].back();

                while (curr != i) {
                    cycle.push_back(curr);
                    curr = path[curr].back();
                }

                int length = 1;
                unordered_map<int, bool> loop;
                loop[i] = true;
                curr = i;
                int index = 0;

                while (index < cycle.size()) {
                    for (int j = 0; j < path[curr].size(); j++) {
                        if (not loop[path[curr][j]]) {
                            loop[path[curr][j]] = true;
                            length += 1;
                        }
                    }

                    index += 1;
                    curr = path[curr].back();
                }

                for (int j = 0; j < cycle.size(); j++) {
                    visited[cycle[j]] = length;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "\n";
        }

        cout << visited[i];
    }

    return 0;
}
