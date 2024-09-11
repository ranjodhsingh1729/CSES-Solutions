#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

bool __comp(pair <int, int> a, pair <int, int> b) {
    if (a.second < b.second)
        return true;
    else
        return false;
}

int binarysearch(int x, int l, int r, pair <int, int> arr[]) {
    int p;
    while (l <= r) {
        p = (l+r)/2;
        if (arr[p].second < x) {
            l = p+1;
        } else if (arr[p].second > x) {
            r = p-1;
        } else {
            return arr[p].first;
        }
    }
    return 0;
}


int main() {
    int n, x;
    cin >> n >> x;
    pair <int, int> arr[2*MAXLEN];
    for (int i = 0; i < n; i++) {
        arr[i].first = i+1;
        cin >> arr[i].second;
    }
    sort(arr, arr+n, __comp);

    int i, tmp;
    for (i = 0; i < n-1; i++) {
        tmp = binarysearch(x-arr[i].second, i+1, n-1, arr);
        
        if (tmp)
            break;
    }

    if (i < n-1)
        cout << arr[i].first << ' ' << tmp << '\n';
    else
        cout << "IMPOSSIBLE" << '\n';


    return 0;
}