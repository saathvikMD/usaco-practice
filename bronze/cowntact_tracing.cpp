// Problem: Cowntact Tracing
// Contest: USACO 2020 US Open Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1037

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);

    int n, t;

    cin >> n >> t;

    string infected;

    cin >> infected;

    vector<vector<int>> meetings(t, vector<int>(3));

    for (int i = 0; i < t; i++) {
        int time, x, y;

        cin >> time >> x >> y;

        meetings[i][0] = time;
        meetings[i][1] = x;
        meetings[i][2] = y;
    }

    sort(meetings.begin(), meetings.end());

    int possibilities = 0, max_k_overall = 0, min_k_overall = INT_MAX;

    for (int i = 0; i < n; i++) {
        bool passed_test = false;

        if (infected[i] == '1') {
            for (int k = 0; k <= t; k++) {
                string curr_infected(n, '0');
                vector<int> infected_number(n, 0);

                curr_infected[i] = '1';

                for (int j = 0; j < t; j++) {
                    if (curr_infected[meetings[j][1] - 1] == '1' and curr_infected[meetings[j][2] - 1] == '1') {
                        infected_number[meetings[j][1] - 1] += 1;
                        infected_number[meetings[j][2] - 1] += 1;
                    } else if (curr_infected[meetings[j][1] - 1] == '1' and infected_number[meetings[j][1] - 1] < k) {
                        curr_infected[meetings[j][2] - 1] = '1';
                        infected_number[meetings[j][1] - 1] += 1;
                    } else if (curr_infected[meetings[j][2] - 1] == '1' and infected_number[meetings[j][2] - 1] < k) {
                        curr_infected[meetings[j][1] - 1] = '1';
                        infected_number[meetings[j][2] - 1] += 1;
                    }
                }

                if (curr_infected == infected) {
                    passed_test = true;

                    if (k == t) {
                        max_k_overall = INT_MAX;
                    } else {
                        max_k_overall = max(max_k_overall, k);
                    }

                    min_k_overall = min(min_k_overall, k);
                }
            }

            if (passed_test) {
                possibilities += 1;
            }
        }
    }

    cout << possibilities << " ";

    if (min_k_overall == INT_MAX) {
        cout << "Infinity" << " ";
    } else {
        cout << min_k_overall << " ";
    }

    if (max_k_overall == INT_MAX) {
        cout << "Infinity";
    } else {
        cout << max_k_overall;
    }

    return 0;
}
