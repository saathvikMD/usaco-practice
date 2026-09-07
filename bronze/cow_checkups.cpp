// Problem: Cow Checkups
// Contest: USACO January 2025 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1469

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> counts(n + 1, 0);

    int original_count = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            original_count += 1;
        }
    }

    counts[original_count] += n;

    for (int i = 1; i < n - 1; i++) {
        int left = i - 1, right = i + 1;
        int count = original_count;

        while (left >= 0 and right < n) {
            count += - (a[left] == b[left]) - (a[right] == b[right]) + (a[right] == b[left]) + (a[left] == b[right]);
            left -= 1;
            right += 1;

            counts[count] += 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        int left = i, right = i + 1;
        int count = original_count;

        while (left >= 0 and right < n) {
            count += - (a[left] == b[left]) - (a[right] == b[right]) + (a[right] == b[left]) + (a[left] == b[right]);
            left -= 1;
            right += 1;

            counts[count] += 1;
        }
    }

    for (int i = 0; i <= n; i++) {
        cout << counts[i] << "\n";
    }

    return 0;
}
