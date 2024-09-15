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
    int n, m;
    cin >> n >> m;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector <vector <int>> dp(n+1, vector <int>(m+1));

    if (arr[0]) {
        dp[0][arr[0]] = 1;
    } else {
        for (int i = 1; i <= m; i++)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (arr[i]) {
            int j = arr[i];
            dp[i][j] = dp[i-1][j];
            if (1 <= j+1 && j+1 <= m) {
                dp[i][j] = mod((dp[i][j] + dp[i-1][j+1]), MOD);
            }
            if (1 <= j-1 && j-1 <= m) {
                dp[i][j] = mod((dp[i][j] + dp[i-1][j-1]), MOD);
            }
        } else {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (1 <= j+1 && j+1 <= m) {
                    dp[i][j] = mod((dp[i][j] + dp[i-1][j+1]), MOD);
                }
                if (1 <= j-1 && j-1 <= m) {
                    dp[i][j] = mod((dp[i][j] + dp[i-1][j-1]), MOD);
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    ll sum = 0;
    for (int j = 1; j <= m; j++) {
        sum = mod((sum + dp[n-1][j]), MOD);
    }

    cout << sum  << '\n';
    return 0;
}