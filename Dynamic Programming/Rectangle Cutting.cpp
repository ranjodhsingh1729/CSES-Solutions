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
    int a, b;
    cin >> a >> b;

    int tmp, dp[501][501] = { 0 };

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (max(i, j) % min(i, j) == 0) {
                dp[i][j] = max(i, j) / min(i, j) - 1;
            } else {
                tmp = INT_MAX;
                for (int x = 1; x < i; x++) {
                    tmp = min(tmp, dp[x][j]+dp[i-x][j]+1);
                }
                for (int y = 1; y < j; y++) {
                    tmp = min(tmp, dp[i][y]+dp[i][j-y]+1);
                }
                dp[i][j] = tmp;
            }
        }
    }

    cout << dp[a][b] << '\n';

    return 0;
}