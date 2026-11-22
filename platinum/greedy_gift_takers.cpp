// Problem: Greedy Gift Takers
// Contest: USACO December 2017 Platinum
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=770

#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int> &pos, int n) {
    vector<int> count(pos.size() + 1, 0);

    for (int i = 0; i < n; i++) {
        count[pos[i]] += 1;
    }

    int total = 0;

    for (int i = 1; i <= n; i++) {
        total += count[i];

        if (total >= i) {
            return true;
        }
    }

    return false;
}

int main() {
    freopen("greedy.in", "r", stdin);
    freopen("greedy.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> pos(n);

    for (int i = 0; i < n; i++) {
        int cut;

        cin >> cut;

        pos[i] = n - cut;
    }

    int low = 0;
    int high = n - 1;
    int blocked = n;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (possible(pos, mid)) {
            blocked = min(blocked, mid);
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << n - blocked;

    return 0;
}
