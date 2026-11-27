// Problem: Secret Cow Code
// Contest: USACO January 2017 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=692

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("cowcode.in", "r", stdin);
    freopen("cowcode.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long n;

    cin >> s >> n;

    vector<long long> doubles;
    doubles.push_back(s.length());

    while (doubles.back() <= n) {
        doubles.push_back(doubles.back() * 2);
    }

    int index = doubles.size() - 1;

    while (index > 0) {
        if (n == doubles[index - 1] + 1) {
            n -= 1;
        } else if (n > doubles[index - 1] + 1){
            n -= doubles[index - 1] + 1;
        }

        index -= 1;
    }

    cout << s[n - 1];

    return 0;
}
