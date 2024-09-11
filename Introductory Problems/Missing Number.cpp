#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    ll n, x;
    cin >> n;
    
    ll esum = 0;
    ll tsum = n*(n+1)/2;

    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        esum += x;
    }

    cout << tsum - esum << '\n';

    return 0;
}