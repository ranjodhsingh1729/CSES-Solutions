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
    int n;
    cin >> n;

    ll x = n*(n+1)/2;
    vector <vector <ll>> dp(501, vector<ll>(125251, 0));

    dp[0][0] = 1;
    if (x % 2 == 0) {
        x /= 2;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= x; j++) {
                dp[i][j] = dp[i-1][j] % MOD;
                if (j >= i)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
        cout << dp[n-1][x] << '\n';
    } else {
        cout << 0 << '\n';
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= x; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}