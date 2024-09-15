#include <bits/stdc++.h>


#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const ll MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll arr[(int)(1e6+1)] = { 0 };

ll ways(int n) {
    if (n <= 1) {
        return 1;
    } else {
        if (!arr[n]) {
            ll cnt = 0;
            for (int i =  1; i <= 6; i++) {
                if (n >= i) {
                    cnt += ways(n-i);
                } else {
                    break;
                }
            }
            arr[n] = cnt % MOD;
        }
        return arr[n];
    }
}


int main() {
    int n;
    cin >> n;
    cout << ways(n) << '\n';

    return 0;
}