// Problem: The Bovine Shuffle
// Contest: USACO December 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=764

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> shuffle(n);
    vector<int> in(n, 0);

    for (int i = 0; i < n; i++) {
        int pos;

        cin >> pos;

        shuffle[i] = pos - 1;
        in[pos - 1] += 1;
    }

    int count = n;

    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            count -= 1;

            queue<int> q;
            q.push(i);

            while (not q.empty()) {
                int cow = q.front();
                q.pop();

                in[shuffle[cow]] -= 1;

                if (in[shuffle[cow]] == 0) {
                    q.push(shuffle[cow]);
                    in[shuffle[cow]] = -1;
                    count -= 1;
                }
            }
        }
    }

    cout << count;

    return 0;
}  
