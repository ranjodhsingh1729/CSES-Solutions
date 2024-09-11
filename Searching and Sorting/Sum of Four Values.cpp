#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;



int main() {
    ll n, x;
    cin >> n >> x;
    ll arr[1001];

    unordered_map <ll, vector <ll>> mp;
    mp.reserve(1001 * 1001);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    
    
    return 0;
}