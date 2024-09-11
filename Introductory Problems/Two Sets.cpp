#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    if (n % 4 == 0 || (n+1) % 4 == 0) {
        cout << "YES" << '\n';

        ll sum = n*(n+1)/4;
        int j = 0, k = 0, arr_a[1000000], arr_b[1000000];
        for (int i = n; i > 0; i--) {
            if (sum - i >= 0) {
                sum -= i;
                arr_a[j++] = i;
            } else {
                arr_b[k++] = i;
            }
        }

        cout << j << '\n';
        for (int i = 0; i < j; i++) {
            cout << arr_a[i] << ' ';
        }
        cout << '\n';

        cout << k << '\n';
        for (int i = 0; i < k; i++) {
            cout << arr_b[i] << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}