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
    int arr[MAXN] = { 0 }, ans[MAXN] = { 0 };

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];

        k = i-1;
        while (arr[k] >= arr[i]) {
            k = ans[k];
        }
        ans[i] = k;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}