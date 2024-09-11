#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN  = 2e5+1;
const int SIZE = 2*MAXN;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int n;
triple arr[MAXN];
int ans[MAXN][2] = { 0 };
int magicarr[SIZE] = { 0 };
set <int> values;
map <int, int> mp;


// where the magic happens :)
void reg(int val, int id) {
    for (int i = id; i < SIZE; i += -i&i) {
        magicarr[i] += val;
    }
}


int get(int id) {
    int cnt = 0;
    for (int i = id; i > 0; i -= -i&i) {
        cnt += magicarr[i];
    }
    return cnt;
}



int main() {
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        values.insert(a);
        values.insert(b);
        arr[i] = {i, a, b};
    }
    sort(arr, arr+n, [](triple a, triple b) {
        return a[1] == b[1] ? a[2] > b[2] : a[1] < b[1];
    });

    // assigning unique ids for magic to be managable :)
    int id = 1;
    for (auto& x: values) {
        mp[x] = id++;
    }

    int idx;
    for (int i = n-1; i >= 0; i--) {
        id = mp[arr[i][2]];
        idx = arr[i][0];

        ans[idx][0] = get(id);
        reg(1, id);
    }

    fill(magicarr, magicarr+SIZE, 0);
    for (int i = 0; i < n; i++) {
        id = mp[arr[i][2]];
        idx = arr[i][0];

        ans[idx][1] = i-get(id-1);
        reg(1, id);
    }


    for (int i = 0; i < n; i++) {
        cout << (ans[i][0] ? 1 : 0) << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        cout << (ans[i][1] ? 1 : 0) << ' ';
    }
    cout << '\n';

    return 0;
}