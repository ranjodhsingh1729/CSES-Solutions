#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, k;
    cin >> n >> k;

    int arr[MAXN];
    map <int, int> mp;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll r = 0, uq = 0, cnt = 0;
    for (int l = 0; l < n; l++) {
        while  (r < n && (mp[arr[r]] >= 1 || uq < k)) {
            mp[arr[r]]++;
            if (mp[arr[r++]] == 1) uq++;
        }

        cnt += r-l;
        mp[arr[l]]--;
        if (!mp[arr[l]]) uq--;
    }

    cout << cnt << '\n';

    return 0;
}