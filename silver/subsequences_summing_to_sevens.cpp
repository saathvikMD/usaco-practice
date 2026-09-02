// Problem: Subsequences Summing to Sevens
// Contest: USACO January 2016 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=595

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;

    cin >> n;

    vector<int> first_occurrence(7, INT_MAX);
    vector<int> last_occurrence(7, -1);
    int sum = 0;

    first_occurrence[0] = -1;

    for (int i = 0; i < n; i++) {
        int number;

        cin >> number;

        sum += number % 7;

        first_occurrence[sum % 7] = min(first_occurrence[sum % 7], i);
        last_occurrence[sum % 7] = max(last_occurrence[sum % 7], i);
    }

    int longest = 0;

    for (int i = 0; i < 7; i++) {
        if (last_occurrence[i] != -1 and first_occurrence[i] != INT_MAX) {
            if (last_occurrence[i] - first_occurrence[i] > longest) {
                longest = last_occurrence[i] - first_occurrence[i];
            }
        }
    }

    cout << longest;

    return 0;
}
