#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    int arr[2*MAXLEN];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - cur <= 1) {
            cur += arr[i];
        } else {
            cout << cur+1 << '\n'; return;
        }
    }
    cout << cur+1 << '\n';
}

int main() {
    solve();

    return 0;
}