// Problem: Moo Route
// Contest: USACO January 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1280

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> crosses(n);

    for (int i = 0; i < n; i++) {
        cin >> crosses[i];
    }

    string moves = "";
    int subtract = 0;
    int backtrack = -1;

    for (int i = 0; i < n; i++) {
        int curr_crosses = crosses[i] - subtract;

        while (curr_crosses > 2) {
            int index = i;
            string front = "";
            string back = "";

            while (index < n and crosses[index] > 2) {
                crosses[index] -= 2;
                index += 1;
                front += "R";
                back += "L";
            }

            moves += front + back;
            curr_crosses -= 2;
        }

        if (curr_crosses == 2) {
            if (backtrack == -1) {
                subtract = 1;
            }

            backtrack = max(backtrack, i);
            moves += "R";
        } else if (curr_crosses == 1) {
            moves += "R";
        }
    }

    while (n - 1 >= backtrack) {
        moves += "L";
        n -= 1;
    }

    cout << moves;

    return 0;
}
