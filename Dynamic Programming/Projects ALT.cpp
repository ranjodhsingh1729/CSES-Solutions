#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n;
    cin >> n;

    vector <triple> arr(MAXN);
    map <int, int> compress;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][1]++;
        compress[arr[i][0]], compress[arr[i][1]];
    }

    int pts = 0;
    for (auto &x: compress) {
        x.second = pts++;
    }

    vector <vector <pair <int, int>>> starts(pts);
    for (int i = 0; i < n; i++) {
        starts[compress[arr[i][1]]].emplace_back( compress[arr[i][0]], arr[i][2] );
    }

    vector <ll> dp(pts, 0);
    for (int i = 0; i < pts; i++) {
        if (i > 0) {
            dp[i] = dp[i-1];
        }
        for (auto &x: starts[i]) {
            dp[i] = max(dp[i], dp[x.first]+x.second);
        }
    }

    cout << dp[pts-1] << '\n';

    return 0;
}