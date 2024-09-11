#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


ll f(ll x, ll n, ll arr[]) {
    ll sum = 0, tmp;
    for (int i = 0; i < n; i++) {
        tmp = x / arr[i];
        
        if (sum > LONG_LONG_MAX - tmp)
            return LONG_LONG_MAX;
        else
            sum += tmp;
    }
    return sum;
}

int main() {
    ll n, t;
    cin >> n >> t;
    ll arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll tmp;
    ll l = 0, h = LONG_LONG_MAX, p;
    while (l < h) {
        p = (l + h) / 2;
        tmp = f(p, n, arr);
        if (tmp < t) {
            l = p+1;
        } else {
            h = p;
        }
    }

    cout << (l+h)/2 << '\n';

    return 0;
}