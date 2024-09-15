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
    int arr[1001];
    int brr[1001];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        cin >> brr[i];


    vector<vector<int>> dp(n + 1, vector<int>(x + 1));

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - arr[i-1] >= 0) {
                dp[i][j] = max(dp[i-1][j], brr[i-1]+dp[i-1][j-arr[i-1]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= x; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][x] << '\n';


    return 0;
}