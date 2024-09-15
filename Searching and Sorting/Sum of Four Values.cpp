#include <bits/stdc++.h>
 
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
 
using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 


int main() {    
    int n, x;
    int arr[MAXN];

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map <int, set <pair <int, int>>> pairs;

    int i, j, tmp = -1;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            pairs[arr[i]+arr[j]].insert({i, j});
        }
    }


    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            tmp = arr[i]+arr[j];
            if (pairs.find(x-tmp) != pairs.end()) {
                for (auto p: pairs[x-tmp]) {
                    if (i != p.first && j != p.first && i != p.second && j != p.second) {
                        cout << i+1 << ' ' << j+1 << ' ' << p.first+1 << ' ' << p.second+1   << '\n';
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';
    return 0;
}