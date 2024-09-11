#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    ll n, arr[20];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll a, b, best = INF;
    for (int i = 0; i < (1<<n); i++) { // :)
        a = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) { // :)
                a += arr[j];
            } else {
                b += arr[j];
            }
        }
        best = min(best, abs(a-b));
    }

    cout << best << '\n';
}


int main() {
    FIXIO;

    ll t;
    t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}