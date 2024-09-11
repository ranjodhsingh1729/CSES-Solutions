#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int arr[2*MAXLEN], brr[2*MAXLEN];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];

    sort(arr, arr+n);
    sort(brr, brr+m);

    bool f;
    int ans, pos;
    ans = pos = 0;

    for (int i = 0; i < m; i++) {
        f = false;
        while (pos < n) {
            if (arr[pos] > brr[i]+k) {
                break;
            }

            if (arr[pos] < brr[i]-k) {
                pos++;
                continue;
            }

            f = true; break;
        }

        if (f) {
            ans++;
            pos++;
        }
    }

    cout << ans << '\n';

    return 0;
}