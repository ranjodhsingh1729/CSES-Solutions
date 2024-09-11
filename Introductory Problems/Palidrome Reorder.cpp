#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;


int main() {
    string x;
    cin >> x;
    map <char, unsigned int> freq;

    for (auto &c: x) {
        freq[c]++;
    }

    bool solexist = true;
    char centerel = '\0';
    bool islenodd = (bool) (x.size() & 1);
    for (auto i = freq.begin(); i != freq.end(); i++) {
        if (i->second & 1) {
            if (!islenodd || centerel) {
                solexist = false;
                cout << "NO SOLUTION" << '\n';
                break;
            } else {
                centerel = i->first;
            }
        }
    }

    if (solexist) {
        for (auto i = freq.begin(); i != freq.end(); i++) {
            for (unsigned int j = 0; j < (i->second)/2; j++) {
                cout << i->first;
            }
        }
        if (centerel) cout << centerel;
        for (auto i = freq.rbegin(); i != freq.rend(); i++) {
            for (unsigned int j = 0; j < (i->second)/2; j++) {
                cout << i->first;
            }
        }
    }

    return 0;
}