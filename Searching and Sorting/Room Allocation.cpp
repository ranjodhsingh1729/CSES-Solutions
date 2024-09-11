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
    set <int> rooms;
    vector <triple> ranges;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        rooms.insert(i+1);
        ranges.push_back({a, 0, i+1});
        ranges.push_back({b, 1, i+1});
    }
    stable_sort(ranges.begin(), ranges.end());

    int best = 0, ans[MAXN];
    for (int i = 0; i < 2*n; i++) {
        if (ranges[i][1]) {
            rooms.insert(ans[ranges[i][2]]);
        } else {
            ans[ranges[i][2]] = *rooms.begin();
            rooms.erase(rooms.begin());
        }

        best = max(best, ans[ranges[i][2]]);
    }

    cout << best << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}