// Problem: Angry Cows
// Contest: USACO January 2016 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=594

#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<int> &hay, int n, int k, int r) {
    int index = 0;

    while (k > 0) {
        int next = upper_bound(hay.begin(), hay.end(), hay[index] + 2LL * r) - hay.begin();

        if (next == n) {
            return true;
        }

        index = next;
        k -= 1;
    }

    return false;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> hay(n);

    for (int i = 0; i < n; i++) {
        cin >> hay[i];
    }

    sort(hay.begin(), hay.end());

    int low = 0;
    int high = 1000000000;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (possible(hay, n, k, mid)) {
            high = mid - 1;
            ans = min(ans, mid);
        } else {
            low = mid + 1;
        }
    }

    cout << ans;

    return 0;
}
