// Problem: Do You Know Your ABCs?
// Contest: USACO December 2020 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1059

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long> numbers(7);

    for (long long i = 0; i < 7; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    long long abc = numbers[6];
    long long a = numbers[0];

    numbers.erase(numbers.begin() + 6);
    numbers.erase(numbers.begin() + 0);

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (numbers[i] + numbers[j] == abc - a) {
                vector<long long> numbers2 = {numbers[i], numbers[j], a};
                sort(numbers2.begin(), numbers2.end());

                cout << numbers2[0] << " " << numbers2[1] << " " << numbers2[2];

                return 0;
            }
        }
    }

    return 0;
}
