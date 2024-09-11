#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    for (ll k = 1; k <= n; k++) {
        if (k == 1) {
            cout << 0 << '\n';
        } else if (k == 2) {
            cout << 6 << '\n';
        } else if (k == 3) {
            cout << 28 << '\n';
        } else if (k == 4) {
            cout << 96 << '\n';
        } else {
            cout << k*k*(k*k-1)/2 - (4*(k-4)*(k-4) + 20*(k-4) + 24) << '\n';
        }
    }

    return 0;
}