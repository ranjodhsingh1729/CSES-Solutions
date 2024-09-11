#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    int m = 1000000007;

    int ans = 2;
    for (int i = 1; i < n; i++) {
        ans = (ans * 2) % m;
    }

    cout << ans << '\n';
    return 0;
}