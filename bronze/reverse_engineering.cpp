// Problem: Reverse Engineering
// Contest: USACO December 2022 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1253

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;

    for (int index = 0; index < t; index++) {
        int n, m;

        cin >> n >> m;

        vector<pair<string, string>> test(m);

        for (int i = 0; i < m; i++) {
            cin >> test[i].first >> test[i].second;
        }

        bool pass = true;
        bool matched = false;

        int if_index, if_equal, if_return;

        while (pass) {
            pass = false;

            for (int i = 0; i < n and not pass; i++) {
                for (int j = 0; j < 2 and not pass; j++) {
                    for (int k = 0; k < 2 and not pass; k++) {
                        pass = true;
                        matched = false;

                        for (int p = 0; p < test.size() and pass; p++) {
                            if (test[p].first[i] - '0' == j) {
                                if (test[p].second[0] - '0' != k) {
                                    pass = false;
                                } else {
                                    matched = true;
                                }
                            }
                        }

                        if (not matched) {
                            pass = false;
                        }

                        if (pass) {
                            if_index = i;
                            if_equal = j;
                            if_return = k;
                        }
                    }
                }
            }

            if (pass) {
                for (int i = test.size() - 1; i >= 0; i--) {
                    if (test[i].first[if_index] - '0' == if_equal) {
                        test.erase(test.begin() + i);
                    }
                }
            }
        }

        pass = true;

        if (test.size() > 0) {
            string compare = test[0].second;

            for (int i = 1; i < test.size() and pass; i++) {
                if (compare != test[i].second) {
                    pass = false;
                }
            }
        }

        if (pass) {
            cout << "OK" << "\n";
        }  else {
            cout << "LIE" << "\n";
        }
    }

    return 0;
}
