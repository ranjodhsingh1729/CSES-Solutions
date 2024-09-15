#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    ll t;
    cin >> t;
    ll n, dp[1000001][2];
    while (t--) {
        cin >> n;

        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][1] = (4*dp[i-1][1] + dp[i-1][0])%MOD;
            dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%MOD;
        }

        cout << (dp[n-1][0] + dp[n-1][1])%MOD << '\n';
    }

    return 0;
}