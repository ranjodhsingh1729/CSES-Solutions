#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    
    ll x, y;
    while (t--) {
        cin >> x >> y;

        if (x > y) {
            if (x & 1) {
                cout << ((x - 1) * (x - 1) + 1) + y - 1 << '\n';
            } else {
                cout << (x * x) - y + 1 << '\n';
            }
        } else {
            if (y & 1) {
                cout << y * y - x + 1 << '\n';
            } else {
                cout << ((y - 1) * (y - 1) + 1) + x - 1 << '\n';
            }
        }
    }

    return 0;
}