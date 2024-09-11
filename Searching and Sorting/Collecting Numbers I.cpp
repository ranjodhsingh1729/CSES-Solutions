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
    int tmp, arr[2*MAXLEN+1];
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[tmp] = i;
    }

    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (arr[i-1] > arr[i])
            ans++;

    cout << ans << '\n';

    return 0;
}