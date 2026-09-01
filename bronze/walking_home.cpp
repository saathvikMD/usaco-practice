// Problem: Walking Home
// Contest: USACO December 2021 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1157

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        int paths = 0;

        for (int starting_dir = 0; starting_dir < 2; starting_dir++) {
            bool direction = starting_dir;
            int x = 0;
            int y = 0;

            for (int i = (direction ? x : y); i < n; i++) {
                if (grid[x][y] == 'H') {
                    break;
                } else if (x == n - 1 and y == n - 1) {
                    paths += 1;
                    break;
                } else if (x == n - 1) {
                    bool passed = true;

                    for (int index = y; index < n; index++) {
                        if (grid[x][index] == 'H') {
                            passed = false;
                            break;
                        }
                    }

                    if (passed) {
                        paths += 1;
                        break;
                    }
                } else if (y == n - 1) {
                    bool passed = true;

                    for (int index = x; index < n; index++) {
                        if (grid[index][y] == 'H') {
                            passed = false;
                            break;
                        }
                    }

                    if (passed) {
                        paths += 1;
                        break;
                    }
                }

                int temp_x = x;
                int temp_y = y;
                int temp_direction = direction;

                direction = not direction;

                if (x > 0 or y > 0) {
                    for (int j = (direction ? x : y); j < n and k > 1; j++) {
                        if (grid[x][y] == 'H') {
                            break;
                        } else if (x == n - 1 and y == n - 1) {
                            paths += 1;
                            break;
                        } else if (x == n - 1) {
                            bool passed = true;

                            for (int index = y; index < n; index++) {
                                if (grid[x][index] == 'H') {
                                    passed = false;
                                    break;
                                }
                            }

                            if (passed) {
                                paths += 1;
                                break;
                            }
                        } else if (y == n - 1) {
                            bool passed = true;

                            for (int index = x; index < n; index++) {
                                if (grid[index][y] == 'H') {
                                    passed = false;
                                    break;
                                }
                            }

                            if (passed) {
                                paths += 1;
                                break;
                            }
                        }

                        int temp_x1 = x;
                        int temp_y1 = y;
                        int temp_direction1 = direction;

                        direction = not direction;

                        if (x > temp_x or y > temp_y) {
                            for (int o = (direction ? x : y); o < n and k > 2; o++) {
                                if (grid[x][y] == 'H') {
                                    break;
                                } else if (x == n - 1 and y == n - 1) {
                                    paths += 1;
                                    break;
                                } else if (x == n - 1) {
                                    bool passed = true;

                                    for (int index = y; index < n; index++) {
                                        if (grid[x][index] == 'H') {
                                            passed = false;
                                            break;
                                        }
                                    }

                                    if (passed) {
                                        paths += 1;
                                        break;
                                    }
                                } else if (y == n - 1) {
                                    bool passed = true;

                                    for (int index = x; index < n; index++) {
                                        if (grid[index][y] == 'H') {
                                            passed = false;
                                            break;
                                        }
                                    }

                                    if (passed) {
                                        paths += 1;
                                        break;
                                    }
                                }

                                if (direction) {
                                    x += 1;
                                } else {
                                    y += 1;
                                }

                            }
                        }

                        direction = temp_direction1;

                        if (direction) {
                            x = temp_x1 + 1;
                            y = temp_y1;
                        } else {
                            y = temp_y1 + 1;
                            x = temp_x1;
                        }
                    }
                }

                direction = temp_direction;

                if (direction) {
                    x = temp_x + 1;
                    y = temp_y;
                } else {
                    y = temp_y + 1;
                    x = temp_x;
                }

            }
        }

        cout << paths << endl;
    }

    return 0;
}
