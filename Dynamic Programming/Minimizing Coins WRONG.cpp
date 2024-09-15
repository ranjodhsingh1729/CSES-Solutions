#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int dp[(int)(1e6+1)] = {0};

int solve(int x, int n, int arr[]) {
    int curr, best = INT_MAX;
    for (int i = 0; i < n; i++) {
        curr = x / arr[i];
        if (curr) {
            if (x%arr[i] && !dp[x%arr[i]]) {
                dp[x%arr[i]] = solve(x%arr[i], n, arr);
            }
            
            if (dp[x%arr[i]] == -1) {
                curr = INT_MAX;
            } else {
                curr += dp[x%arr[i]];
            }

            best = min(best, curr);
        }
    }
    return (best != INT_MAX ? best : -1);
}


int main() {
    int n, x;
    cin >> n >> x;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    cout << solve(x, n, arr) << '\n';


    return 0;
}