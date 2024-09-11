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
    cin >> n >> k;
    pair <int, int> arr[MAXN];

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        arr[i] = make_pair(b, a);
    }
    sort(arr, arr+n);

    multiset <int> pclose;
    multiset <int> :: iterator itr;
    for (int i = 0; i < k; i++) {
        pclose.insert(0);
    }

    int skips = 0;
    for (int i = 0; i < n; i++) {
        itr = pclose.upper_bound(arr[i].second);
        if (itr != pclose.begin()) {
            itr = prev(itr);
            pclose.erase(itr);
            pclose.insert(arr[i].first);
        } else {
            skips++;
        }
    }

    cout << n-skips << '\n';

    return 0;
}