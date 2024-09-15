#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+1;

int main() {
    int n;
    cin >> n;
    char tmp;
    bool arr[1001][1001];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            arr[i][j] = (tmp == '.');
        }
    }

    int dp[1001][1001] = { 0 };

    dp[0][0] = arr[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j]) {
                if (j-1 >= 0 && arr[i][j-1]) {
                    dp[i][j] = mod((dp[i][j] + dp[i][j-1]), MOD);
                }
                if (i-1 >= 0 && arr[i-1][j]) {
                    dp[i][j] = mod((dp[i][j] + dp[i-1][j]), MOD);
                }
            }
        }
    }

    cout << dp[n-1][n-1] << '\n';


    return 0;
}