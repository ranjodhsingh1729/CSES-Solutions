#include <bits/stdc++.h>
 
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
 
using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;
 
 
int bin(int x, int l, int h, int *arr[]) {
    int p;
    while (l < h) {
        p = (l+h)/2;
        if (x > *arr[p]) {
            l = p+1;
        } else if (x < *arr[p]) {
            h = p;
        } else {
            return p;
        }
    }
    return -1;
}
 
 
int main() {
    int n, x;
    cin >> n >> x;
    int arr[MAXN], *brr[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        brr[i] = arr+i;
    }
    sort(brr, brr+n, [](auto a, auto& b) {
        return *a < *b;
    });
 
 
    int i, j, tmp = -1;
    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            tmp = bin(x-*brr[i]-*brr[j], j+1, n, brr);
 
            if (tmp != -1)
                break;
        }
 
        if (j < n) {
            break;
        }
    }
 
    if (tmp != -1) {
        cout << brr[i] - arr + 1 << ' ';
        cout << brr[j] - arr + 1 << ' ';
        cout << brr[tmp] - arr + 1 << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
 
    return 0;
}