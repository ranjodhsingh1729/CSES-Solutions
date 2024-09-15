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
    ll arr[5001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll dp[5001][5001][2];


    int l, r;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n-i+1; j++) {
            l = j;
            r = j+i;
            dp[i][j][0] = max(arr[l]+dp[i-1][j+1][1], arr[r-1]+dp[i-1][j][1]);
            dp[i][j][1] = min(dp[i-1][j+1][0], dp[i-1][j][0]);
        }
    }

    cout << dp[n][0][0] << '\n';
    return 0;
}