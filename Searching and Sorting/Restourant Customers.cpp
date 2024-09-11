#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n;
    cin >> n;
    int arr[2*MAXLEN], brr[2*MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> brr[i];
    }
    sort(arr, arr+n);
    sort(brr, brr+n);

    int tmp;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        tmp = lower_bound(brr, brr+n, arr[i-1]) - brr;
        if (i - tmp > ans)
            ans = i - tmp;
    }

    cout << ans << '\n';

    return 0;
}