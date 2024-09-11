#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

typedef struct {
    int open;
    int close;
} movie;

bool paircomp(movie a, movie b) {
    if (a.close < b.close) {
        return true;
    } else {
        return false;
    }
}


int main() {
    int n;
    cin >> n;
    movie arr[2*MAXLEN];
    for (int i = 0; i < n; i++)
        cin >> arr[i].open >> arr[i].close;
    sort(arr, arr+n, paircomp);

    int pclose = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (i < n && arr[i].open < pclose) i++;

        if (i < n) {
            ans++;
            pclose = arr[i].close;
        } else {
            break;
        }
    }

    cout << ans << '\n';

    return 0;
}