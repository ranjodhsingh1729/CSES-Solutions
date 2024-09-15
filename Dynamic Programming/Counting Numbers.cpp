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

ll dp[20][10];
bool tight[20];

ll solve(ll x) {
    if (x <= 10)
        return x;

    memset(dp, 0, sizeof(dp));  
    memset(tight, 0, sizeof(tight));

    int k = 0, digit[20] = { 0 };
    while (x) {
        digit[k++] = x % 10;
        x /= 10;
    }
    reverse(digit, digit+k);

    tight[0] = true;
    for (int i = 1; i < k; i++) {
        tight[i] = tight[i-1] && (digit[i] != digit[i-1]);
    }

    for (int i = 1; i < digit[0]; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < k; i++) {
        if (tight[i-1]) {
            for (int j = 0; j < digit[i]; j++) {
                if (j != digit[i-1]) dp[i][j]++;
            }
        }

        for (int j = 1; j <= 9; j++) {
            dp[i][j]++;
        }

        for (int j = 0; j <= 9; j++) {
            for (int l = 0; l <= 9; l++) {
                if (j != l) dp[i][l] += dp[i-1][j];
            }
        }
    }

    ll cnt = tight[k-1];
    for (int j = 0; j <= 9; j++) {
        cnt += dp[k-1][j];
    }
    return cnt;
}


int main() {
    ll a, b;
    cin >> a >> b;

    cout << solve(b) - solve(a-1) << '\n';

    return 0;
}