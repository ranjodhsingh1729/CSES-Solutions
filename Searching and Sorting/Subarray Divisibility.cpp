#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define mod(a, b) ((a) - (b)*(floor((double) (a) / (b))))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;




int main() {
    map <ll, ll> mp;

    ll n;
    ll arr[MAXN];
    cin >> n;

    ll cnt = 0;
    ll pre = 0;
    arr[0] = 0;
    mp[arr[0]]++;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        
        pre = mod(arr[i], n);
        cnt += mp[pre];

        mp[pre]++;
    }

    cout << cnt << '\n';
    
    return 0;
}