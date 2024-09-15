#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, x;
    cin >> n >> x;
    int arr[101];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int dp[1000001] = { 0 };

    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n && i >= arr[j]; j++) {
            dp[i] = (dp[i] + dp[i-arr[j]]) % MOD;
        }
    }

    cout << dp[x] << '\n';


    return 0;
}