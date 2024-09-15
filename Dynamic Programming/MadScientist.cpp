#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;
    string x, y;
    cin >> x >> y;

    int f = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f == 0 && x[i] != y[i]) {
            cnt++;
            f = 1;
        }
        if (f == 1 && x[i] == y[i]) {
            f = 0;
        }
    }

    cout << cnt << '\n';

    return 0;
}