#include <bits/stdc++.h>


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const ll MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


ll ways_iter(int n) {
    ll arr[7];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    arr[4] = 8;
    arr[5] = 16;
    for (int i = 6; i <= n; i++) {
        arr[6] = 0;
        for (int j = 1; j <= 6; j++) {
            arr[6] += arr[6-j];
        }
        arr[6] %= MOD;
        for (int j = 1; j <= 6; j++) {
            arr[j-1] = arr[j];
        }
    }
    return arr[(n < 6 ? n : 6)];
}



int main() {
    int n;
    cin >> n;
    cout << ways_iter(n) << '\n';

    return 0;
}