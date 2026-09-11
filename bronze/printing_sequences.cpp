// Problem: Printing Sequences
// Contest: USACO February 2025 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1493

#include <bits/stdc++.h>
using namespace std;

bool check1(vector<int> numbers) {
    int val = numbers[0];

    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] != val) {
            return false;
        }
    }

    return true;
}

bool check2(vector<int> numbers) {
    int prev_val = numbers[0];
    int prev_index = 0;
    vector<int> lengths;
    vector<int> values;

    for (int i = 0; i < numbers.size(); i++) {
        if (prev_val != numbers[i]) {
            lengths.push_back(i - prev_index);
            values.push_back(prev_val);
            prev_val = numbers[i];
            prev_index = i;
        }
    }

    lengths.push_back(numbers.size() - prev_index);
    values.push_back(prev_val);

    if (lengths.size() <= 2) {
        return true;
    } else {
        if (lengths.size() % 2 == 1) {
            return false;
        }

        prev_val = values[0];
        int constant_length = lengths[0];

        for (int i = 0; i < lengths.size(); i += 2) {
            if (values[i] != prev_val or lengths[i] != constant_length) {
                return false;
            }
        }

        constant_length = lengths[1];
        prev_val = values[1];

        for (int i = 1; i < lengths.size(); i += 2) {
            if (values[i] != prev_val or lengths[i] != constant_length) {
                return false;
            }
        }
    }

    return true;
}

bool check3(vector<int> numbers) {
    if (check2(numbers)) {
        return true;
    }

    int prev_val = numbers[0];

    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != prev_val) {
            if (check2(vector<int>(numbers.begin() + i, numbers.end()))) {
                return true;
            }

            break;
        }
    }

    prev_val = numbers.back();

    for (int i = numbers.size() - 1; i >= 0; i--) {
        if (numbers[i] != prev_val) {
            if (check2(vector<int>(numbers.begin(), numbers.begin() + i + 1))) {
                return true;
            }

            break;
        }
    }

    for (int i = 1; i <= numbers.size(); i++) {
        if (numbers.size() % i == 0) {
            bool possible = true;

            for (int j = 0; j < numbers.size(); j++) {
                if (numbers[j] != numbers[j % i]) {
                    possible = false;
                }
            }

            if (possible) {
                for (int j = 1; j < i; j++) {
                    vector<int> left(numbers.begin(), numbers.begin() + j);
                    vector<int> right(numbers.begin() + j, numbers.begin() + i);

                    if ((check1(left) and check2(right)) or (check1(right) and check2(left))) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        vector<int> numbers(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        if (k == 1) {
            if (check1(numbers)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else if (k == 2) {
            if (check2(numbers)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        } else if (k == 3) {
            if (check3(numbers)) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
