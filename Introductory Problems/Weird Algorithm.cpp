#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    cout << n << ' ';
    while (n != 1) {
        if (n & 1) {
            n = 3*n + 1;
        } else {
            n = n / 2;
        }
        cout << n << ' ';
    }
    cout << '\n';
    
    return 0;
}