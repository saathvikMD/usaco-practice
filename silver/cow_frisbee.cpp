// Problem: Cow Frisbee
// Contest: USACO January 2022 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1183

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    long long distance = 0;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        while (not s.empty() and cows[s.top()] < cows[i]) {
            s.pop();
        }

        if (not s.empty()) {
            distance += i - s.top() + 1;
        }

        s.push(i);
    }

    s = stack<int>();

    for (int i = n - 1; i >= 0; i--) {
        while (not s.empty() and cows[s.top()] < cows[i]) {
            s.pop();
        }

        if (not s.empty()) {
            distance += s.top() - i + 1;
        }

        s.push(i);
    }

    cout << distance;

    return 0;
}
