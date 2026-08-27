// Problem: Back and Forth
// Contest: USACO December 2018 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=857

#include <bits/stdc++.h>
using namespace std;

vector<int> readings(0);

int recursion(int tank1, int tank2, int iteration, vector<int> buckets1, vector<int> buckets2, int index) {
    if (iteration == 4) {
        readings.push_back(tank1);
        return 0;
    }

    if (iteration % 2 == 0) {
        if (index != -1) {
            int bucket = buckets2[index];
            buckets2.erase(buckets2.begin() + index);
            buckets1.push_back(bucket);
        }

        for (int i = 0; i < buckets1.size(); ++i) {
            recursion(tank1 - buckets1[i], tank2 + buckets1[i], iteration + 1, buckets1, buckets2, i);
        }
    } else {
        if (index != -1) {
            int bucket = buckets1[index];
            buckets1.erase(buckets1.begin() + index);
            buckets2.push_back(bucket);
        }

        for (int i = 0; i < buckets2.size(); ++i) {
            recursion(tank1 + buckets2[i], tank2 - buckets2[i], iteration + 1, buckets1, buckets2, i);
        }
    }

    return 0;
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> buckets1(10);
    vector<int> buckets2(10);

    for (int i = 0; i < 10; ++i) {
        cin >> buckets1[i];
    }

    for (int i = 0; i < 10; ++i) {
        cin >> buckets2[i];
    }

    recursion(1000, 1000, 0, buckets1, buckets2, -1);

    sort(readings.begin(), readings.end());
    int prev = -1, count = 0;

    for (int i = 0; i < readings.size(); ++i) {
        if (readings[i] != prev) {
            count += 1;
        }

        prev = readings[i];
    }

    cout << count;

    return 0;
}
