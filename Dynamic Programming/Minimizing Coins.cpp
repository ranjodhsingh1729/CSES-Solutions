#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, x;
    cin >> n >> x;
    int arr[MAXN];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    int dp[(int)(1e6+1)];
    for (int i = 0; i <= x; i++) dp[i] = INT_MAX;

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i < arr[j])
                break;
            dp[i] = min(dp[i], dp[i-arr[j]]);
        }
    }

    cout << ((dp[x] != INT_MAX) ? dp[x] : -1) << '\n'; 

    return 0;
}