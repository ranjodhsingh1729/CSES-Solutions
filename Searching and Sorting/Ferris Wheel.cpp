#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, x;
    cin >> n >> x;
    int arr[2*MAXLEN];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);

    int l = 0, ans = 0;
    for (int r = n-1; l <= r; r--) {
        if (arr[l] + arr[r] <= x)
            l++;
        ans++;
    }

    cout << ans << '\n';

    


    return 0;
}