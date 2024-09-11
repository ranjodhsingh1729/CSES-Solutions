#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n;
    cin >> n;
    int arr[2*MAXLEN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int median;
    if (n % 2) {
        median = arr[n/2];
    } else {
        median =  ( (ll) arr[n/2-1] + arr[n/2]) / 2;
    }
    
    ll cost = 0;
    for (int i = 0; i < n; i++) {
        cost += abs(arr[i] - median);
    }

    cout << cost << '\n';

    return 0;
}