// Problem: COW Splits
// Contest: USACO 2026 First Contest Bronze
// Link: https://usaco.org/index.php?cpid=1540&page=viewproblem2

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> uncommon(3, vector<char>(3));
    uncommon[0][1] = 'C';
    uncommon[0][2] = 'W';
    uncommon[1][2] = 'O';

    int t, k;

    cin >> t >> k;

    for (int iteration = 0; iteration < t; iteration++) {
        if (iteration != 0) {
            cout << "\n";
        }

        int n;

        cin >> n;

        string s;

        cin >> s;

        if (n % 2 == 0) {
            vector<bool> variations(3, false);

            for (int i = 0; i < n; i++) {
                if (s[i * 3] == 'C') {
                    variations[0] = true;
                } else if (s[i * 3] == 'O') {
                    variations[1] = true;
                } else {
                    variations[2] = true;
                }
            }

            bool possible = true;

            for (int i = 0; i < s.length()/2; i++) {
                if (s[i] != s[i + s.length()/2]) {
                    possible = false;

                    break;
                }
            }

            if (possible) {
                variations[0] = false;
                variations[1] = false;
                variations[2] = false;
            }

            if (accumulate(variations.begin(), variations.end(), 0) <= 1) {
                cout << 1 << "\n";

                for (int i = 0; i < s.length(); i++) {
                    if (i != 0) {
                        cout << " ";
                    }

                    cout << 1;
                }
            } else if (accumulate(variations.begin(), variations.end(), 0) == 2) {
                cout << 2 << "\n";

                char different;

                for (int i = 0; i < 3; i++) {

                    for (int j = i + 1; j < 3; j++) {
                        if (variations[i] and variations[j]) {
                            different = uncommon[i][j];

                            break;
                        }
                    }
                }

                for (int i = 0; i < s.length(); i++) {
                    if (i != 0) {
                        cout << " ";
                    }

                    if (s[i] == different) {
                        cout << 1;
                    } else {
                        cout << 2;
                    }
                }
            } else {
                cout << 2 << "\n";

                vector<int> answer(s.length());

                for (int i = 0; i < n/2; i++) {
                    if (s[i * 3] == s[i * 3 + 3 * n/2]) {
                        for (int j = 0; j < 3; j++) {
                            answer[i * 3 + j] = 1;
                            answer[i * 3 + j + 3 * n/2] = 1;
                        }
                    } else {
                        if (s[i * 3] == s[i * 3 + 3 * n/2 + 1]) {
                            for (int j = 0; j < 2; j++) {
                                answer[i * 3 + j] = 1;
                                answer[i * 3 + j + 3 * n/2 + 1] = 1;
                            }

                            answer[i * 3 + 2] = 2;
                            answer[i * 3 + 3 * n/2] = 2;
                        } else {
                            for (int j = 0; j < 2; j++) {
                                answer[i * 3 + j + 1] = 1;
                                answer[i * 3 + j + 3 * n/2] = 1;
                            }

                            answer[i * 3] = 2;
                            answer[i * 3 + 3 * n/2 + 2] = 2;
                        }
                    }
                }

                for (int i = 0; i < s.length(); i++) {
                    if (i != 0) {
                        cout << " ";
                    }

                    cout << answer[i];
                }
            }
        } else {
            cout << -1;
        }
    }

    return 0;
}
