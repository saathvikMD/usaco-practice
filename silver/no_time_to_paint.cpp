// Problem: No Time to Paint
// Contest: USACO January 2021 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1087

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    string s;

    cin >> s;

    vector<pair<int, int>> intervals;

    for (int i = 0; i < 26; i++) {
        char letter = 'A' + i;
        bool started = false;
        int prev_start = 0;
        int prev_end = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == letter) {
                if (started) {
                    prev_end = j;
                } else {
                    started = true;
                    prev_start = j;
                    prev_end = j;
                }
            } else if (s[j] < letter) {
                if (started) {
                    intervals.push_back({prev_start, prev_end});
                    started = false;
                }
            }
        }

        if (started) {
            intervals.push_back({prev_start, prev_end});
        }
    }

    sort(intervals.begin(), intervals.end(), [](auto a, auto b) {return a.second < b.second;});

    vector<int> starts;
    vector<int> ends;

    for (int j = 0; j < intervals.size(); j++) {
        starts.push_back(intervals[j].first);
        ends.push_back(intervals[j].second);
    }

    sort(starts.begin(), starts.end());

    for (int i = 0; i < q; i++) {
        int start, end;

        cin >> start >> end;

        start -= 1;
        end -= 1;

        int left = lower_bound(starts.begin(), starts.end(), start) - starts.begin();
        int right = ends.end() - upper_bound(ends.begin(), ends.end(), end);

        cout << left + right << '\n';
    }

    return 0;
}
