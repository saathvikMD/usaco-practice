// Problem: Perimeter
// Contest: USACO January 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=895

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<vector<int>> sources(n, vector<int>(n, false));

    for (int i = 0; i < n; i++) {
        string row;

        cin >> row;

        for (int j = 0; j < n; j++) {
            if (row[j] == '#') {
                sources[i][j] = true;
            }
        }
    }

    int max_area = 0;
    int max_perimeter = 0;
    vector<vector<int>> visited(n, vector<int>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sources[i][j] and not visited[i][j]) {
                visited[i][j] = true;

                vector<pair<int, int>> current;
                current.push_back({i, j});

                int curr_area = 0;
                int perimeter = 0;

                while (current.size() > 0) {
                    vector<pair<int, int>> new_current;

                    for (int k = 0; k < current.size(); k++) {
                        curr_area += 1;

                        if (current[k].first > 0 and sources[current[k].first - 1][current[k].second]) {
                            if (not visited[current[k].first - 1][current[k].second]) {
                                visited[current[k].first - 1][current[k].second] = true;
                                new_current.push_back({current[k].first - 1, current[k].second});
                            }
                        } else {
                            perimeter += 1;
                        }

                        if (current[k].first < n - 1 and sources[current[k].first + 1][current[k].second]) {
                            if (not visited[current[k].first + 1][current[k].second]) {
                                visited[current[k].first + 1][current[k].second] = true;
                                new_current.push_back({current[k].first + 1, current[k].second});
                            }
                        } else {
                            perimeter += 1;
                        }

                        if (current[k].second > 0 and sources[current[k].first][current[k].second - 1]) {
                            if (not visited[current[k].first][current[k].second - 1]) {
                                visited[current[k].first][current[k].second - 1] = true;
                                new_current.push_back({current[k].first, current[k].second - 1});
                            }
                        } else {
                            perimeter += 1;
                        }

                        if (current[k].second < n - 1 and sources[current[k].first][current[k].second + 1]) {
                            if (not visited[current[k].first][current[k].second + 1]) {
                                visited[current[k].first][current[k].second + 1] = true;
                                new_current.push_back({current[k].first, current[k].second + 1});
                            }
                        } else {
                            perimeter += 1;
                        }
                    }

                    current = new_current;
                }

                if (curr_area > max_area) {
                    max_area = curr_area;
                    max_perimeter = perimeter;
                } else if (curr_area == max_area and max_perimeter > perimeter) {
                    max_perimeter = perimeter;
                }
            }
        }
    }

    cout << max_area << " " << max_perimeter;

    return 0;
}
