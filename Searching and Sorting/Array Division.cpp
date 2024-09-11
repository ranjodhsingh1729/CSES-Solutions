#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

const ll MAX_SUM = 2e5*1e9;

bool check(int k, ll mx_sm, int n, int arr[]) {
    ll cr_sm = 0, subarrcnt = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mx_sm) return false;

        cr_sm += arr[i];
        if (cr_sm > mx_sm) {
            cr_sm = arr[i];
            subarrcnt++;
        }   
    }

    return (subarrcnt <= k);
}


int main() {
    int n, k;
    cin >> n >> k;
    int arr[MAXN];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 1, r = MAX_SUM, p;
    while (l < r) {
        p = (l+r)/2;
        if (check(k, p, n, arr)) {
            r = p;
        } else {
            l = p+1;
        }
    }

    cout << l << '\n';

    return 0;
}