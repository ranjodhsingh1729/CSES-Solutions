#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    string x;
    cin >> x;

    int cur = x[0], rep = 1, maxrep = 1;
    for (int i = 1; i < x.length(); i++) {
        if (cur == x[i]) {
            rep++;
        } else {
            maxrep = max(rep, maxrep);
            cur = x[i], rep = 1;
        }
    }

    cout << max(rep, maxrep) << '\n';

    return 0;
}