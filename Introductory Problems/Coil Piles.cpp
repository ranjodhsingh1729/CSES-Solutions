#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    int a, b;
    int x, y;
    while (t--) {
        cin >> a >> b;
        x = min(a, b);
        y = max(a, b);

        if (x == 0 && y == 0) {
            cout << "YES" << '\n'; continue;
        }

        if (x == 0) {
            cout << "NO" << '\n'; continue;
        }
        
        if (y-x <= x && (2*x-y) % 3 == 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }

    return 0;
}