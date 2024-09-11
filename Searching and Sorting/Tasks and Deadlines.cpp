#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;



int main() {
    int n;
    cin >> n;
    pair <int, int> arr[MAXN];
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = make_pair(a, b);
    }
    sort(arr, arr+n, [](auto& left, auto &right) {
        return left.first == right.first ? left.second > right.second : left.first < right.first;
    });

    ll prfx[MAXN];
    prfx[0] = arr[0].first;

    ll sum = arr[0].second - prfx[0];
    for (int i = 1; i < n; i++) {
        prfx[i] = prfx[i-1] + arr[i].first;
        sum += arr[i].second - prfx[i];
    }

    cout << sum << '\n';
    
    return 0;
}
