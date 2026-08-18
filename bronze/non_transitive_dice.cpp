// Problem: Non-Transitive Dice
// Contest: USACO January 2022 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1180

#include <bits/stdc++.h>
using namespace std;

pair<int,int> check (int dice[8]) {
    int acount = 0;
    int bcount = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 4; j < 8; j++) {
            if (dice[i] > dice[j]) {
                acount += 1;
            } else if (dice[i] < dice[j]) {
                bcount += 1;
            }
        }
    }

    return {acount, bcount};
}

int main() {
    int n;

    cin >> n;

    int dice[n][8];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> dice[i][j];
        }
    }

    int acount, bcount;
    bool nts;

    for (int i = 0; i < n; i++) {
        nts = false;

        pair<int, int> result = check(dice[i]);

        acount = result.first;
        bcount = result.second;

        if (acount > bcount) {
            int ac[8];
            int bc[8];

            ac[0] = dice[i][0];
            ac[1] = dice[i][1];
            ac[2] = dice[i][2];
            ac[3] = dice[i][3];
            bc[0] = dice[i][4];
            bc[1] = dice[i][5];
            bc[2] = dice[i][6];
            bc[3] = dice[i][7];

            for (int a = 1; a <= 10; a++) {
                ac[4] = a;
                bc[4] = a;
                for (int b = 1; b <= 10; b++) {
                    ac[5] = b;
                    bc[5] = b;
                    for (int c = 1; c <= 10; c++) {
                        ac[6] = c;
                        bc[6] = c;
                        for (int d = 1; d <= 10; d++) {
                            ac[7] = d;
                            bc[7] = d;

                            if (not nts) {
                                pair<int, int> acresult = check(ac);
                                pair<int, int> bcresult = check(bc);

                                if (bcresult.second < bcresult.first and acresult.first < acresult.second) {
                                    nts = true;
                                }
                            }
                        }
                    }
                }
            }
        } else if (bcount > acount) {
            int ac[8];
            int bc[8];

            ac[0] = dice[i][0];
            ac[1] = dice[i][1];
            ac[2] = dice[i][2];
            ac[3] = dice[i][3];
            bc[0] = dice[i][4];
            bc[1] = dice[i][5];
            bc[2] = dice[i][6];
            bc[3] = dice[i][7];

            for (int a = 1; a <= 10; a++) {
                ac[4] = a;
                bc[4] = a;
                for (int b = 1; b <= 10; b++) {
                    ac[5] = b;
                    bc[5] = b;
                    for (int c = 1; c <= 10; c++) {
                        ac[6] = c;
                        bc[6] = c;
                        for (int d = 1; d <= 10; d++) {
                            ac[7] = d;
                            bc[7] = d;

                            if (not nts) {
                                pair<int, int> acresult = check(ac);
                                pair<int, int> bcresult = check(bc);

                                if (bcresult.second > bcresult.first and acresult.first > acresult.second) {
                                    nts = true;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (nts) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
