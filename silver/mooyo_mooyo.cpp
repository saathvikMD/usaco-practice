// Problem: Mooyo Mooyo
// Contest: USACO December 2018 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=860

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mooyomooyo.in", "r", stdin);
    freopen("mooyomooyo.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<vector<int>> board(n, vector<int>(10));

    for (int i = 0; i < n; i++) {
        string s;

        cin >> s;

        for (int j = 0; j < 10; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int biggest;

    while (true) {
        biggest = 0;

        vector<vector<int>> visited(n, vector<int>(10, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] != 0 and visited[i][j] == 0) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    int count = 1;

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        if (x > 0 and board[x - 1][y] == board[x][y]) {
                            if (visited[x - 1][y] == 0) {
                                visited[x - 1][y] = 1;
                                q.push({x - 1, y});
                                count += 1;
                            }
                        }

                        if (x < n - 1 and board[x + 1][y] == board[x][y]) {
                            if (visited[x + 1][y] == 0) {
                                visited[x + 1][y] = 1;
                                q.push({x + 1, y});
                                count += 1;
                            }
                        }

                        if (y > 0 and board[x][y - 1] == board[x][y]) {
                            if (visited[x][y - 1] == 0) {
                                visited[x][y - 1] = 1;
                                q.push({x, y - 1});
                                count += 1;
                            }
                        }

                        if (y < 9 and board[x][y + 1] == board[x][y]) {
                            if (visited[x][y + 1] == 0) {
                                visited[x][y + 1] = 1;
                                q.push({x, y + 1});
                                count += 1;
                            }
                        }
                    }

                    visited[i][j] = count;
                    biggest = max(biggest, count);
                }
            }
        }

        if (biggest >= k) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 10; j++) {
                    if (visited[i][j] >= k) {
                        queue<pair<int, int>> q;
                        q.push({i, j});
                        int original_val = board[i][j];

                        while (q.size() > 0) {
                            int x = q.front().first;
                            int y = q.front().second;
                            visited[x][y] = 0;
                            q.pop();

                            board[x][y] = 0;

                            if (x > 0 and board[x - 1][y] == original_val and visited[x - 1][y] > 0) {
                                q.push({x - 1, y});
                                visited[x - 1][y] = 0;
                            }

                            if (x < n - 1 and board[x + 1][y] == original_val and visited[x + 1][y] > 0) {
                                q.push({x + 1, y});
                                visited[x + 1][y] = 0;
                            }

                            if (y > 0 and board[x][y - 1] == original_val and visited[x][y - 1] > 0) {
                                q.push({x, y - 1});
                                visited[x][y - 1] = 0;
                            }

                            if (y < 9 and board[x][y + 1] == original_val and visited[x][y + 1] > 0) {
                                q.push({x, y + 1});
                                visited[x][y + 1] = 0;
                            }
                        }
                    }
                }
            }

            for (int i = 0; i < 10; i++) {
                int count = 0;

                for (int j = n - 1; j >= 0; j--) {
                    if (board[j][i] != 0) {
                        int prev_val = board[j][i];
                        board[j][i] = 0;
                        board[n - count - 1][i] = prev_val;
                        count += 1;
                    }
                }
            }
        } else {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j];
        }

        cout << endl;
    }
}
