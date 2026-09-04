// Problem: Cowntact Tracing
// Contest: USACO US Open 2020 Bronze
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

    vector<tuple<int, int, int>> meetings;

    for (int i = 0; i < t; i++) {
        int time, cow1, cow2;

        cin >> time >> cow1 >> cow2;

        meetings.push_back({time, cow1, cow2});
    }

    sort(meetings.begin(), meetings.end());

    int possibilities = 0;
    int min_k = INT_MAX, max_k = 0;

    for (int i = 0; i < n; i++) {
        if (infected[i] == '1') {
            bool passed = false;

            for (int k = 0; k <= t; k++) {
                vector<int> curr_infected(n, -1);
                curr_infected[i] = 0;

                for (int j = 0; j < t; j++) {
                    int cow1 = get<1>(meetings[j]) - 1, cow2 = get<2>(meetings[j]) - 1;

                    if (curr_infected[cow1] != -1) {
                        if (curr_infected[cow2] == -1) {
                            if (curr_infected[cow1] < k) {
                                curr_infected[cow2] = 0;
                            }
                        } else {
                            curr_infected[cow2] += 1;
                        }

                        curr_infected[cow1] += 1;
                    } else if (curr_infected[cow2] != -1) {
                        if (curr_infected[cow2] < k) {
                            curr_infected[cow1] = 0;
                        }

                        curr_infected[cow2] += 1;
                    }
                }

                bool match = true;

                for (int i = 0; i < n and match; i++) {
                    if (curr_infected[i] == -1 and infected[i] == '1') {
                        match = false;
                    } else if (curr_infected[i] != -1 and infected[i] == '0') {
                        match = false;
                    }
                }

                if (match) {
                    passed = true;
                    min_k = min(min_k, k);
                    max_k = max(max_k, (k == t ? INT_MAX : k));
                }
            }

            if (passed) {
                possibilities += 1;
            }
        }
    }

    cout << possibilities << " " << min_k << " ";

    if (max_k == INT_MAX) {
        cout << "Infinity";
    } else {
        cout << max_k;
    }

    return 0;
}
