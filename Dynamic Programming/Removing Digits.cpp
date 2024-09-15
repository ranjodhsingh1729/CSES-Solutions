#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int inttostr(int x, int arr[]) {
    int k = 0;
    while (x) {
        arr[k++] = x % 10;
        x /= 10;
    }
    return k;
}


int main() {
    ll n;
    cin >> n;
    
    ll best;
    ll dp[MAXN];
    int k, arr[7];

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        k = inttostr(i, arr);
        dp[i] = best = INT_MAX;
        for (int j = 0; j < k; j++) {
            best = min(best, dp[i-arr[j]]+1);
        }
        dp[i] = best;
    }

    cout << dp[n] << '\n';

    return 0;
}