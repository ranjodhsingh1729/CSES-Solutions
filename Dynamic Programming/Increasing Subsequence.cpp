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
    int arr[200001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int tmp;
    int dp[200001] = {0};

    int k = 0;
    for (int i = 0; i < n; i++) {
        tmp = lower_bound(dp, dp+k, arr[i]) - dp;
        dp[tmp] = arr[i];
        k = max(k, tmp+1);
    }
    
    cout << k << '\n';

    return 0;
}