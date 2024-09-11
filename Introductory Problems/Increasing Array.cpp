#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int n, x;
    cin >> n;

    cin >> x;
    int h = x;

    ll m = 0;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x > h) {
            h = x;
        } else {
            m += h-x;
        }
    }

    cout << m << '\n';
        
    return 0;
}