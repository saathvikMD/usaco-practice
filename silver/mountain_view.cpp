// Problem: Mountain View
// Contest: USACO January 2019 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=896

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<pair<int, int>> mountains;

    for (int i = 0; i < n; i++) {
        int x, y;

        cin >> x >> y;

        int index = lower_bound(mountains.begin(), mountains.end(), make_pair(x, y)) - mountains.begin();
        mountains.insert(mountains.begin() + index, {x, y});

        if (index != 0) {
            if (mountains[index - 1].second - (mountains[index].first - mountains[index - 1].first) >= mountains[index].second) {
                mountains.erase(mountains.begin() + index);
                index = mountains.size() - 1;
            } else {
                while (index != 0 and mountains[index].second - (mountains[index].first - mountains[index - 1].first) >= mountains[index - 1].second) {
                    mountains.erase(mountains.begin() + index - 1);
                    index -= 1;
                }
            }
        }

        if (index != mountains.size() - 1) {
            if (mountains[index + 1].second - (mountains[index + 1].first - mountains[index].first) >= mountains[index].second) {
                mountains.erase(mountains.begin() + index);
            } else {
                while (index != mountains.size() - 1 and mountains[index].second - (mountains[index + 1].first - mountains[index].first) >= mountains[index + 1].second) {
                    mountains.erase(mountains.begin() + index + 1);
                }
            }
        }
    }

    cout << mountains.size();

    return 0;
}
