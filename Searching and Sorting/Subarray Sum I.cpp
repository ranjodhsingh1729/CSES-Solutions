#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, t;
    int arr[MAXN];
    cin >> n >> t;

    ll sum = 0;
    int k = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        sum += arr[i];
        while (sum > t) sum -= arr[k++];

        if (sum == t) cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}