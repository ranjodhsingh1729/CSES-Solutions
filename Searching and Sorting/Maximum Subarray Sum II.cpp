#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, a, b;
    cin >> n >> a >> b;
    ll arr[MAXN];
    map <ll, int> freq;

    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    ll best = arr[a];
    for (int i = 1; i <= n; i++) {
        if (i >= a) {
            freq[arr[i-a]]++;
            best = max(best, arr[i]-(freq.begin()->first));
        }
        if (i >= b) {
            freq[arr[i-b]]--;
            if (!freq[arr[i-b]])
                freq.erase(arr[i-b]);
        }

    }

    cout << best << '\n';
    
    return 0;
}