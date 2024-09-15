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

    triple arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    sort(arr, arr+n, [](auto &a, auto &b){
        return (a[1] == b[1] ? (a[0] == b[0] ? a[2] < b[2] : a[0] < b[0]) : a[1] < b[1]);
    });


    map <int, ll> dp;
    map <int, ll> :: iterator itr;

    dp[arr[0][1]] = arr[0][2];
    for (int i = 1; i < n; i++) {
        itr = dp.lower_bound(arr[i][0]);
        if (itr == dp.begin()) {
            dp[arr[i][1]] = max(arr[i][2], dp.rbegin()->second);
        } else {
            itr = prev(itr);
            dp[arr[i][1]] = max(itr->second + arr[i][2], dp.rbegin()->second);
        }
    }

    // for (auto x: dp) {
    //     cout << x.first << ' ' << x.second << '\n';
    // }

    cout << dp.rbegin()->second << '\n';

    return 0;
}