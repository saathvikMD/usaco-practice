// Problem: Stuck in a Rut
// Contest: USACO December 2020 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1064

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<tuple<int, int, int>> cows(n);
    vector<int> graph(n);

    for (int i = 0; i < n; i++) {
        char dir;
        int x, y;

        cin >> dir >> x >> y;

        cows[i] = {(dir == 'E' ? 1 : 0), x, y};
        graph[i] = i;
    }

    vector<int> blame(n, 0);
    vector<tuple<int, int, int, int>> possible;

    for (int i = 0; i < n; i++) {
        int dir = get<0>(cows[i]);

        for (int j = 0; j < n; j++) {
            if (dir != get<0>(cows[j])) {
                int xtime = get<1>(cows[j]) - get<1>(cows[i]);
                int ytime = get<2>(cows[j]) - get<2>(cows[i]);

                if (dir == 1) {
                    if (xtime > 0 and -ytime > 0 and -ytime < xtime) {
                        possible.push_back({xtime, -ytime, i, j});
                    }
                } else {
                    if (-xtime > 0 and ytime > 0 and -xtime < ytime) {
                        possible.push_back({ytime, -xtime, i, j});
                    }
                }
            }
        }
    }

    sort(possible.begin(), possible.end());
    vector<int> stop(n, INT_MAX);

    for (auto [time, blocker_time, i, j] : possible) {
        if (stop[i] == INT_MAX and stop[j] > blocker_time) {
            stop[i] = time;
            graph[i] = j;
            blame[j]++;
        }
    }

    vector<int> total(n, 0);

    for (int i = 0; i < n; i++) {
        if (blame[i] != 0) {
            int blamed = i;
            int count = blame[i];

            while (graph[blamed] != blamed) {
                blamed = graph[blamed];
                total[blamed] += count;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "\n";
        }

        cout << total[i] + blame[i];
    }

    return 0;
}
