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
    int n, x;
    cin >> n >> x;
    ll arr[21];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector <vector <ll>> dp(2*MAXN, vector <ll> (2, 0));

    for (int i = 0; i < n; i++) {
        dp[(1 << i)] = {1, arr[n-i-1]};
    }

    ll rides, space;
    for (int i = 0; i < (1<<n); i++) {
        if (dp[i][0]) continue;

        dp[i][0] = INT_MAX, dp[i][1] = 0;
        for (int j = 0; j < n; j++) {
            if (!(i&(1<<j))) continue;

            rides = dp[i^(1<<j)][0];
            space = dp[i^(1<<j)][1] + dp[1<<j][1];

            rides = rides + (space>x);
            space = space > x ? dp[1<<j][1] : space;

            if (rides < dp[i][0]) {
                dp[i][0] = rides, dp[i][1] = space;
            }

            if (rides == dp[i][0] && space < dp[i][1]) {
                dp[i][1] = space;
            }

        }

    }

    cout << dp[(1<<n) - 1][0] << '\n';


    return 0;
}