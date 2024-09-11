#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;

int factorial(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) {
        f *= i;
    }
    return f;
}

void __createstrings(string x, string y) {
    if (x.size()) {
        char c = '0';
        y.push_back('0');
        int n = x.size(), m = y.size();
        for (int i = 0; i < n; i++) {
            if (c != x[i]) {
                c = x[i];
                y[m-1] = c;

                x.erase(i, 1);
                __createstrings(x, y);
                x.insert(i, 1, c);
            }
        }
    } else {
        cout << y << '\n';
    }
    
}

void createstrings(string x) {
    string y;
    __createstrings(x, y);
}

int main() {
    string x;
    cin >> x;
    int n = x.size();
    sort(x.begin(), x.end());

    map <char, int> freq;
    for (auto &c: x) {
        freq[c]++;
    }

    int k = factorial(n);
    for (auto i = freq.begin(); i != freq.end(); i++) {
        k /= factorial(i->second);
    }

    cout << k << '\n';
    createstrings(x);

    return 0;
}