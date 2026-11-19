// Problem: Milk Sum
// Contest: USACO 2023 US Open Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1326

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;

    vector<int> milk(n);

    for (int i = 0; i < n; i++) {
        cin >> milk[i];
    }

    vector<int> original = milk;
    sort(milk.begin(), milk.end());

    long long total = 0;
    long long curr_sum = 0;
    vector<long long> sum(n);;

    for (int i = 0; i < n; i++) {
        total += 1LL * milk[i] * (i + 1);
        curr_sum += milk[i];
        sum[i] = curr_sum;
    }

    int q;

    cin >> q;

    for (int iter = 0; iter < q; iter++) {
        int i, j;

        cin >> i >> j;

        int old_value = original[i - 1];
        long long new_total = total;

        if (old_value > j) {
            int low = 0;
            int high = n - 1;
            int start = 0, end = 0;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (milk[mid] == old_value) {
                    start = mid;

                    break;
                } else if (milk[mid] < old_value) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            low = 0;
            high = start;
            end = start;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (milk[mid] >= j) {
                    high = mid - 1;
                    end = min(end, mid);
                } else {
                    low = mid + 1;
                }
            }

            new_total += 1LL * (end + 1) * j - 1LL * (start + 1) * old_value;
            new_total += (start > 0 ? sum[start - 1] : 0) - (end > 0 ? sum[end - 1] : 0);
        } else if (old_value < j) {
            int low = 0;
            int high = n - 1;
            int start = 0, end = 0;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (milk[mid] == old_value) {
                    start = mid;

                    break;
                } else if (milk[mid] < old_value) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            low = start;
            high = n - 1;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (milk[mid] <= j) {
                    low = mid + 1;
                    end = max(end, mid);
                } else {
                    high = mid - 1;
                }
            }

            new_total += 1LL * (end + 1) * j - 1LL * (start + 1) * old_value;
            new_total -= sum[end] - sum[start];
        }

        if (iter > 0) {
            cout << "\n";
        }

        cout << new_total;
    }

    return 0;
}
