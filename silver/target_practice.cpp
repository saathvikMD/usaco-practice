// Problem: Target Practice
// Contest: USACO December 2023 Silver
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1352

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, c;

    cin >> t >> c;

    unordered_map<int, bool> targets;

    for (int i = 0; i < t; i++) {
        int target;

        cin >> target;

        targets[target] = true;
    }

    string commands;

    cin >> commands;

    unordered_map<int, int> doubleleft;
    unordered_map<int, int> left;
    unordered_map<int, int> normal;
    unordered_map<int, int> right;
    unordered_map<int, int> doubleright;

    int pos = 0;

    for (int i = 0; i < c; i++) {
        if (commands[i] == 'L') {
            pos -= 1;
        } else if (commands[i] == 'R') {
            pos += 1;
        } else if (commands[i] == 'F') {
            if (targets.count(pos - 2)) {
                doubleleft[pos - 2] = i;
            }

            if (targets.count(pos - 1)) {
                left[pos - 1] = i;
            }

            if (targets.count(pos) and not normal.count(pos)) {
                normal[pos] = i;
            }

            if (targets.count(pos + 1)) {
                right[pos + 1] = i;
            }

            if (targets.count(pos + 2)) {
                doubleright[pos + 2] = i;
            }
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_doubleleft;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_left;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_normal;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_right;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_doubleright;

    for (auto [target, time] : doubleleft) {
        pq_doubleleft.push({time, target});
    }

    for (auto [target, time] : left) {
        pq_left.push({time, target});
    }

    for (auto [target, time] : normal) {
        pq_normal.push({time, target});
    }

    for (auto [target, time] : right) {
        pq_right.push({time, target});
    }

    for (auto [target, time] : doubleright) {
        pq_doubleright.push({time, target});
    }

    int extra_doubleleft = doubleleft.size();
    int extra_left = left.size();
    int extra_right = right.size();
    int extra_doubleright = doubleright.size();
    int normal_count = 0;
    int max_targets = normal.size();
    pos = 0;

    for (int i = 0; i < c; i++) {
        if (not pq_doubleleft.empty() and pq_doubleleft.top().first == i) {
            int target = pq_doubleleft.top().second;
            pq_doubleleft.pop();

            if (doubleleft[target] != INT_MAX) {
                extra_doubleleft -= 1;
                doubleleft[target] = INT_MAX;
            }
        }

        if (not pq_left.empty() and pq_left.top().first == i) {
            int target = pq_left.top().second;
            pq_left.pop();

            if (left[target] != INT_MAX) {
                extra_left -= 1;
                left[target] = INT_MAX;
            }
        }

        if (not pq_right.empty() and pq_right.top().first == i) {
            int target = pq_right.top().second;
            pq_right.pop();

            if (right[target] != INT_MAX) {
                extra_right -= 1;
                right[target] = INT_MAX;
            }
        }

        if (not pq_doubleright.empty() and pq_doubleright.top().first == i) {
            int target = pq_doubleright.top().second;
            pq_doubleright.pop();

            if (doubleright[target] != INT_MAX) {
                extra_doubleright -= 1;
                doubleright[target] = INT_MAX;
            }
        }

        if (commands[i] == 'L') {
            max_targets = max(max_targets, normal_count + extra_right + (targets.count(pos) and not normal.count(pos) and not right.count(pos) ? 1 : 0));
            max_targets = max(max_targets, normal_count + extra_doubleright);
            pos -= 1;
        } else if (commands[i] == 'R') {
            max_targets = max(max_targets, normal_count + extra_left + (targets.count(pos) and not normal.count(pos) and not left.count(pos) ? 1 : 0));
            max_targets = max(max_targets, normal_count + extra_doubleleft);
            pos += 1;
        } else {
            max_targets = max(max_targets, normal_count + extra_left);
            max_targets = max(max_targets, normal_count + extra_right);
        }

        if (not pq_normal.empty() and pq_normal.top().first == i) {
            int target = pq_normal.top().second;
            pq_normal.pop();

            if (doubleleft.count(target) and doubleleft[target] != INT_MAX) {
                extra_doubleleft -= 1;
                doubleleft[target] = INT_MAX;
            }

            if (left.count(target) and left[target] != INT_MAX) {
                extra_left -= 1;
                left[target] = INT_MAX;
            }

            if (right.count(target) and right[target] != INT_MAX) {
                extra_right -= 1;
                right[target] = INT_MAX;
            }

            if (doubleright.count(target) and doubleright[target] != INT_MAX) {
                extra_doubleright -= 1;
                doubleright[target] = INT_MAX;
            }

            normal_count += 1;
        }
    }

    cout << max_targets;

    return 0;
}
