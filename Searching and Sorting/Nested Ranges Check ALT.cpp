#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN  = 2e5+1;
const int SIZE = 2*MAXN;
const ll INF = 0x3f3f3f3f3f3f3f3f;





int main() {
    int n;
    cin >> n;
    triple arr[MAXN];
    int ans[MAXN][2] = { 0 };

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = {i, a, b};
    }
    sort(arr, arr+n, [](triple a, triple b) {
        return a[1] == b[1] ? a[2] > b[2] : a[1] < b[1];
    });

    int mnc = INT_MAX;
    for (int i = n-1; i >= 0; i--) {
        if (mnc <= arr[i][2]) {
            ans[arr[i][0]][0] = 1;
        } else {
            mnc = arr[i][2];
        }
    }

    int mxc = 0;
    for (int i = 0; i < n; i++) {
        if (mxc >= arr[i][2]) {
            ans[arr[i][0]][1] = 1;
        } else {
            mxc = arr[i][2];
        }
    }


    for (int i = 0; i < n; i++) {
        cout << (ans[i][0] ? 1 : 0) << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << (ans[i][1] ? 1 : 0) << ' ';
    }
    cout << '\n';

    return 0;
}