// Problem: Majority Opinion
// Contest: USACO January 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1371

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;

        cin >> n;

        int possible = false;
        vector<bool> answer(n + 1, false);

        int prev_number = -1;
        int prev_prev = -2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            if (temp == prev_prev) {
                answer[prev_prev] = true;
                possible = true;
            }

            prev_prev = prev_number;

            if (temp == prev_number) {
                count += 1;
            } else {
                if (prev_number >= 0) {
                    if (count > 1) {
                        answer[prev_number] = true;
                        possible = true;
                    }
                }

                prev_number = temp;
                count = 1;
            }
        }

        if (count > 1) {
            answer[prev_number] = true;
            possible = true;
        }

        if (possible) {
            bool answered = false;

            for (int i = 0; i <= n; i++) {
                if (answer[i]) {
                    if (answered) {
                        cout << " ";
                    }

                    cout << i;
                    answered = true;
                }
            }

            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
