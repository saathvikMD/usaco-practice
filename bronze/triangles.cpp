// Problem: Triangles
// Contest: USACO February 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1011

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;

    cin >> n;

    long long points[n][2];

    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    long long area, maxarea = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i][0] == points[j][0]) {
                for (int k = 0; k < n; k++) {
                    if (k != j and k != i) {
                        if (points[k][1] == points[i][1]) {
                            area = abs(points[i][1] - points[j][1]) * abs(points[i][0] - points[k][0]);

                            if (area > maxarea) {
                                maxarea = area;
                            }
                        } else if (points[k][1] == points[j][1]) {
                            area = abs(points[i][1] - points[j][1]) * abs(points[j][0] - points[k][0]);

                            if (area > maxarea) {
                                maxarea = area;
                            }
                        }
                    }
                }
            } else if (points[i][1] == points[j][1]) {
                for (int k = 0; k < n; k++) {
                    if (k != j and k != i) {
                        if (points[k][0] == points[i][0]) {
                            area = abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[k][1]);

                            if (area > maxarea) {
                                maxarea = area;
                            }
                        } else if (points[k][0] == points[j][0]) {
                            area = abs(points[i][0] - points[j][0]) * abs(points[j][1] - points[k][1]);

                            if (area > maxarea) {
                                maxarea = area;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << maxarea;

    return 0;
}
