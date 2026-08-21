// Problem: Even More Odd Photos
// Contest: USACO January 2021 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1084

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    int odds = 0, evens = 0, temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;

        if (temp % 2 == 0) {
            evens += 1;
        } else {
            odds += 1;
        }
    }

    while (odds > evens) {
        evens += 1;
        odds -= 2;
    }

    if (odds == evens) {
        cout << odds * 2;
    } else {
        cout << odds * 2 + 1;
    }

    return 0;
}
