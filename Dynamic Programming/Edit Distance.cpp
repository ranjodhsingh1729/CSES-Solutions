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


int minofthree(int a, int b, int c) {
    return ((a < b) ? (a < c ? a : c) : (b < c ? b : c));
}


int main() {
    string x, y;
    cin >> x >> y;
    int n = x.size(), m = y.size();

    int dp[5001][5001];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = minofthree(
                dp[i-1][j]+1,
                dp[i][j-1]+1,
                dp[i-1][j-1]+(x[i-1]!=y[j-1])
            );
        }
    }


    cout << dp[n][m] << '\n';

    return 0;
}