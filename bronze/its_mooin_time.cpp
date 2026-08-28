// Problem: It's Mooin' Time
// Contest: USACO December 2024 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1445

#include <bits/stdc++.h>
using namespace std;

vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int index(char character) {
    return find(alphabet.begin(), alphabet.end(), character) - alphabet.begin();
}

int main() {
    int n, f;

    cin >> n >> f;

    string file;

    cin >> file;

    vector<vector<vector<int>>> table(26, vector<vector<int>>(26));
    vector<vector<vector<int>>> changes(26, vector<vector<int>>(26));

    for (int i = 2; i < n; i++) {
        if (file[i - 2] != file[i - 1]) {
            if (file[i - 1] == file[i]) {
                int index1 = index(file[i - 1]), index2 = index(file[i - 2]);
                table[index2][index1].push_back(i);

                if (changes[index2][index1].size() > 0 and i - changes[index2][index1].back() < 3) {
                    changes[index2][index1].pop_back();
                }
            } else {
                int index1 = index(file[i - 1]), index2 = index(file[i - 2]);

                if (table[index2][index1].size() == 0 or i - table[index2][index1].back() >= 3) {
                    changes[index2][index1].push_back(i);
                }

                if (file[i - 2] != file[i]) {
                    int index0 = index(file[i]);

                    if (table[index2][index0].size() == 0 or i - table[index2][index0].back() >= 3) {
                        changes[index2][index0].push_back(i);
                    }
                }
            }
        } else {
            if (file[i - 2] != file[i]) {
                int index0 = index(file[i]), index2 = index(file[i - 2]);

                if (table[index2][index0].size() == 0 or i - table[index2][index0].back() >= 3) {
                    changes[index2][index0].push_back(i);
                }
            }
        }

        if (file[i - 1] == file[i]) {
            int index0 = index(file[i]);

            for (int j = 0; j < 26; j++) {
                if (j != index0) {
                    if (table[j][index0].size() == 0 or i - table[j][index0].back() > 2) {
                        changes[j][index0].push_back(i);
                    }
                }
            }
        }
    }

    vector<string> moos;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i != j) {
                int count = table[i][j].size();

                if (count >= f) {
                    moos.push_back(string() + alphabet[i] + alphabet[j] + alphabet[j]);
                } else if (count == f - 1) {
                    if (changes[i][j].size() > 0) {
                        moos.push_back(string() + alphabet[i] + alphabet[j] + alphabet[j]);
                    }
                }
            }
        }
    }

    cout << moos.size() << endl;

    for (int i = 0; i < moos.size(); i++) {
        cout << moos[i] << endl;
    }

    return 0;
}
