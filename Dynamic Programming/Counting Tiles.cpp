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


int n, m;
int dp[1001][1<<10] = { 0 };


void solve(int idx, int cur, int nxt, int col) {
    if (idx == n) {
        dp[col+1][nxt] = (dp[col+1][nxt] + dp[col][cur]) % MOD;
        return;
    }

    if (cur&(1<<idx)) {
        solve(idx+1, cur, nxt, col);
    } else {
        solve(idx+1, cur, nxt|(1<<idx), col);
    if (idx+1 < n && !(cur&(1<<(idx+1)))) {
            solve(idx+2, cur, nxt, col);
        }
    }
}


int main() {
    cin >> n >> m;

    dp[0][0] = 1;
    for (int col = 0; col < m; col++) {
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[col][mask] > 0) {
                solve(0, mask, 0, col);
            }
        }
    }

    cout << dp[m][0] << '\n';
    
    return 0;
}