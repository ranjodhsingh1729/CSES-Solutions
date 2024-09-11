#include <bits/stdc++.h>


#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    map <int, int> ind;
    int n;
    cin >> n;
    int arr[2*MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    int best = 1;
    for (int l = 0, r = 0; r < n; r++) {
        l = max(ind[arr[r]], l);
        best = max(best, r-l+1);

        ind[arr[r]] = r+1;
    }
    cout << best << '\n';


    return 0;
}