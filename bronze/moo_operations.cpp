// Problem: Moo Operations
// Contest: USACO January 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1277

#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;

    cin >> q;

    for (int iteration = 0; iteration < q; iteration++) {
        string moo;

        cin >> moo;

        if (moo.size() >= 3) {
            int operations = INT_MAX;
            
            for (int i = 1; i < moo.size() - 1; i++) {
                if (moo[i] == 'O') {
                    operations = min(operations, (moo[i - 1] == 'M' ? 0 : 1) + (moo[i + 1] == 'O' ? 0 : 1));
                }
            }

            if (operations == INT_MAX) {
                cout << -1 << "\n";
            } else {
                cout << operations + moo.size() - 3 << "\n";
            }
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
