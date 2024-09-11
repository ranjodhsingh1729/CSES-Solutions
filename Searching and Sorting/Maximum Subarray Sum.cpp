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
    int arr[2*MAXLEN];
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    ll cur = arr[0], best = arr[0];
    for (int i = 1; i < n; i++) {
        if (cur < 0) {
            cur = arr[i];
        } else {
            cur += arr[i];
        }
        best = max(cur, best);
    }

    cout << best << '\n';

    return 0;
}