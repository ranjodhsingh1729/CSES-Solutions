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
    int n, m;
    cin >> n >> m;
    int arr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll cnt = 1, d;

    if (!arr[0])
        cnt *= 3;
    for (int i = 1; i < n-1; i++) {
        if (!arr[i]) {
            d = abs(arr[i+1]-arr[i-1]);
            cnt =  mod((cnt * (3-d > 0 ? 3-d : 1)), MOD);
        }
    }
    if (n != 1 && !arr[n-1]) {
        cnt = mod(cnt * 3, MOD);
    }

    cout << cnt << '\n';

    return 0;
}