#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((long long) ((a) - (b)*floor((long double) (a)/(b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const ll MOD = 1e9+7;
const int MAXN = 1e6+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n;
    cin >> n;
    int arr[101];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set <int> dp, tmp;

    for (int i = 0; i < n; i++) {
        tmp.insert(arr[i]);
        for (auto x: dp) {
            tmp.insert(x+arr[i]);
        }
        dp.merge(tmp);
        tmp.clear();
    }

    cout << dp.size() << '\n';
    for (auto x: dp) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}