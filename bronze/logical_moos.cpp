// Problem: Logical Moos
// Contest: USACO US Open 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1419

#include <bits/stdc++.h>
using namespace std;

bool evaluate(vector<string> equation) {
    int n = equation.size();

    bool result = equation[0] == "true";

    for (int i = 2; i < n; i += 2) {
        result = result and equation[i] == "true";
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;

    cin >> n >> q;

    vector<string> equation(n);

    for (int i = 0; i < n; i++) {
        cin >> equation[i];
    }

    vector<pair<int, bool>> left(n);
    vector<pair<int, bool>> right(n);

    int prev_or = -1;
    bool curr_result = false;

    for (int i = 0; i < n; i++) {
        if (equation[i] == "or") {
            curr_result = curr_result or evaluate(vector<string> (equation.begin() + prev_or + 1, equation.begin() + i));
            prev_or = i;
        }

        left[i] = {prev_or, curr_result};
    }

    prev_or = -1;
    curr_result = false;

    for (int i = n - 1; i >= 0; i--) {
        if (equation[i] == "or") {
            curr_result = curr_result or evaluate(vector<string> (equation.begin() + i + 1, equation.begin() + (prev_or == -1 ? n : prev_or)));
            prev_or = i;
        }

        right[i] = {prev_or, curr_result};
    }

    vector<int> falses(n + 1, 0);

    for (int i = 0; i < n; i++) {
        falses[i + 1] = falses[i] + (equation[i] == "false");
    }

    string result = "";

    for (int i = 0; i < q; i++) {
        int l, r;
        string replacing;

        cin >> l >> r >> replacing;

        l -= 1;
        r -= 1;

        bool middle_condition;

        if (replacing == "false") {
            middle_condition = false;
        } else {
            middle_condition = (falses[l] - falses[left[l].first + 1] == 0) and (falses[right[r].first == -1 ? n : right[r].first] - falses[r + 1] == 0);
        }

        result += ((left[l].second or middle_condition or right[r].second) == (replacing == "true") ? 'Y' : 'N');
    }

    cout << result;
}
