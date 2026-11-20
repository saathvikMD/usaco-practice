// Problem: Subset Equality
// Contest: USACO 2022 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1231

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;

    cin >> s >> t;

    vector<int> count_s(18, 0);
    vector<int> count_t(18, 0);

    for (int i = 0; i < s.size(); i++) {
        count_s[s[i] - 'a'] += 1;
    }

    for (int i = 0; i < t.size(); i++) {
        count_t[t[i] - 'a'] += 1;
    }

    vector<vector<bool>> match(18, vector<bool>(18));

    for (int i = 0; i < 18; i++) {
        for (int j = 0; j < 18; j++) {
            if (count_s[i] == count_t[i] and count_s[j] == count_t[j]) {
                string new_s = "", new_t = "";

                for (int k = 0; k < s.size(); k++) {
                    if (s[k] == char('a' + i) or s[k] == char('a' + j)) {
                        new_s += s[k];
                    }
                }

                for (int k = 0; k < t.size(); k++) {
                    if (t[k] == char('a' + i) or t[k] == char('a' + j)) {
                        new_t += t[k];
                    }
                }

                if (new_s == new_t) {
                    match[i][j] = true;
                } else {
                    match[i][j] = false;
                }
            } else {
                match[i][j] = false;
            }
        }
    }

    int q;

    cin >> q;

    for (int i = 0; i < q; i++) {
        string qs;

        cin >> qs;

        bool possible = true;

        for (int j = 0; j < qs.size() and possible; j++) {
            for (int k = 0; k < qs.size() and possible; k++) {
                if (not match[qs[j] - 'a'][qs[k] - 'a']) {
                    possible = false;
                }
            }
        }

        if (possible) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }

    return 0;
}
