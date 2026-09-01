// Problem: Moo Language
// Contest: USACO US Open 2023 Bronze
// Link: https://usaco.org/index.php?page=viewproblem2&cpid=1324

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, c, p;

        cin >> n >> c >> p;

        vector<string> nouns;
        vector<string> transitive_verbs;
        vector<string> intransitive_verbs;
        vector<string> conjunctions;

        for (int i = 0; i < n; i++) {
            string word, type;

            cin >> word >> type;

            if (type == "noun") {
                nouns.push_back(word);
            } else if (type == "transitive-verb") {
                transitive_verbs.push_back(word);
            } else if (type == "intransitive-verb") {
                intransitive_verbs.push_back(word);
            } else {
                conjunctions.push_back(word);
            }
        }

        int original_p = p;
        int original_c = c;

        vector<string> original_nouns = nouns;
        vector<string> original_transitive_verbs = transitive_verbs;
        vector<string> original_intransitive_verbs = intransitive_verbs;
        vector<string> original_conjunctions = conjunctions;

        string final_output = "";
        int final_word_count = 0;
        bool prev_compounding = false;

        for (int i = 0; i <= original_intransitive_verbs.size(); i++) {
            p = original_p;
            c = original_c;

            nouns = original_nouns;
            transitive_verbs = original_transitive_verbs;
            intransitive_verbs = original_intransitive_verbs;
            conjunctions = original_conjunctions;

            string output = "";
            int word_count = 0;
            prev_compounding = false;

            while (p > 0 and ((nouns.size() > 0 and intransitive_verbs.size() > i) or (nouns.size() > 1 and transitive_verbs.size() > 0))) {
                if (intransitive_verbs.size() > i) {
                    output += nouns[nouns.size() - 1] + " ";
                    nouns.pop_back();

                    output += intransitive_verbs[intransitive_verbs.size() - 1];
                    intransitive_verbs.pop_back();

                    word_count += 2;
                } else if (nouns.size() > 1) {
                    output += nouns[nouns.size() - 1] + " ";
                    nouns.pop_back();

                    output += transitive_verbs[transitive_verbs.size() - 1] + " ";
                    transitive_verbs.pop_back();

                    output += nouns[nouns.size() - 1];
                    nouns.pop_back();

                    word_count += 3;

                    while (nouns.size() > min({(int) transitive_verbs.size(), (p - 1) + min((int) conjunctions.size(), p - (prev_compounding ? 1 : 0)), (int) nouns.size() / 2}) * 2 and c > 0) {
                        output += ", " + nouns[nouns.size() - 1];
                        nouns.pop_back();
                        c -= 1;

                        word_count += 1;
                    }
                }

                if (not prev_compounding and conjunctions.size() > 0 and ((nouns.size() > 0 and intransitive_verbs.size() > i) or (nouns.size() > 1 and transitive_verbs.size() > 0))) {
                    output += " " + conjunctions[conjunctions.size() - 1] + " ";
                    conjunctions.pop_back();
                    prev_compounding = true;

                    word_count += 1;
                } else {
                    output += ". ";
                    p -= 1;
                    prev_compounding = false;
                }
            }

            if (word_count > final_word_count) {
                final_word_count = word_count;
                final_output = output;
            }
        }

        cout << final_word_count << "\n";

        if (final_output.length() > 0) {
            final_output.pop_back();
        }

        cout << final_output << "\n";
    }

    return 0;
}
