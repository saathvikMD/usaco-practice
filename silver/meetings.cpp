// Problem: Meetings
// Contest: USACO December 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=967

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

     int n, l;

    cin >> n >> l;

    vector<pair<int, int>> cows(n);
    vector<int> lefts;
    vector<int> rights;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int w, x, d;

        cin >> w >> x >> d;

        if (d == -1) {
            lefts.push_back(x);
        } else {
            rights.push_back(l - x);
        }

        cows[i].first = x;
        cows[i].second = w;
        sum += w;
    }

    sort(cows.begin(), cows.end());
    sort(lefts.begin(), lefts.end());
    sort(rights.begin(), rights.end());

    int left = 0;
    int right = 0;
    long long reached = 0;
    int time = 0;

    while (left < lefts.size() and right < rights.size()) {
        if (lefts[left] <= rights[right]) {
            reached += cows[left].second;
            time = lefts[left];
            left += 1;
        } else {
            reached += cows[n - 1 - right].second;
            time = rights[right];
            right += 1;
        }

        if (reached * 2 >= sum) {
            break;
        }
    }

    if (reached * 2 < sum) {
        if (left < lefts.size()) {
            while (reached * 2 < sum) {
                reached += cows[left].second;
                time = lefts[left];
                left += 1;
            }
        } else {
            while (reached * 2 < sum) {
                reached += cows[n - 1 - right].second;
                time = rights[right];
                right += 1;
            }
        }
    }

    int meetings = 0;

    for (int i = 0; i < rights.size(); i++) {
        for (int j = lefts.size() - 1; j >= 0; j--) {
            if (l - rights[i] < lefts[j]) {
                if (lefts[j] - l + rights[i] <= time * 2) {
                    meetings += 1;
                }
            } else {
                break;
            }
        }
    }

    cout << meetings << endl;

    return 0;
}
