// Problem: Angry Cows
// Contest: USACO January 2016 Gold
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=597

#include <bits/stdc++.h>
using namespace std;

bool possible(const vector<long long> &hay, long long r) {
    long long low = hay[0];
    long long high = hay.back();
    long long ans = -1;

    while (low <= high) {
        long long mid = (low + high) / 2;
        int index = int (upper_bound(hay.begin(), hay.end(), mid) - hay.begin()) - 1;
        bool possible = false;

        if (index == -1) {
            possible = true;
        } else {
            possible = true;
            int latest = mid;
            int latest_seen = mid;
            int radius = r;

            for (int i = index; i >= 0; i--) {
                if (radius >= latest - hay[i]) {
                    latest_seen = hay[i];
                } else if (radius - 2 >= latest_seen - hay[i]) {
                    latest = latest_seen;
                    latest_seen = hay[i];
                    radius -= 2;
                } else {
                    possible = false;

                    break;
                }
            }
        }

        if (possible) {
            low = mid + 1;
            ans = max(ans, mid);
        } else {
            high = mid - 1;
        }
    }

    if (ans != -1) {
        int index = int (upper_bound(hay.begin(), hay.end(), ans) - hay.begin());
        long long latest = ans;
        long long latest_seen = ans;
        long long radius = r;

        for (int i = index; i < hay.size(); i++) {
            if (radius >= hay[i] - latest) {
                latest_seen = hay[i];
            } else if (radius - 2 >= hay[i] - latest_seen) {
                latest = latest_seen;
                latest_seen = hay[i];
                radius -= 2;
            } else {
                return false;
            }
        }

        return true;
    }

    return false;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<long long> hay(n);

    for (int i = 0; i < n; i++) {
        long long location;

        cin >> location;

        hay[i] = location * 2;
    }

    sort(hay.begin(), hay.end());

    long long low = 1;
    long long high = hay.back();
    long long ans = INT_MAX;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (possible(hay, mid)) {
            high = mid - 1;
            ans = min(ans, mid);
        } else {
            low = mid + 1;
        }
    }

    cout << ans / 2 << (ans % 2 == 0 ? ".0" : ".5");

    return 0;
}
