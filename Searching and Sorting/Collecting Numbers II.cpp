#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, m;
    cin >> n >> m;
    int tmp, arr[2*MAXLEN+5], brr[2*MAXLEN+5];

    arr[0] = brr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        arr[i] = tmp;
        brr[tmp] = i;
    }
    arr[n+1] = brr[n+1] = n+1;

    int ans = 1;
    for (int i = 2; i <= n; i++)
        if (brr[i-1] > brr[i])
            ans++;
    
    
    int a, b, x, y;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        x = arr[a], y = arr[b];

        if (a >= brr[x-1] && b < brr[x-1]) ans++; 
        if (a < brr[x-1] && b >= brr[x-1]) ans--; 
        if (brr[x+1] >= a && brr[x+1] < b) ans++; 
        if (brr[x+1] < a && brr[x+1] >= b) ans--; 

        if (b > brr[y-1] && a <= brr[y-1]) ans++; 
        if (b <= brr[y-1] && a > brr[y-1]) ans--; 
        if (brr[y+1] > b && brr[y+1] <= a) ans++;
        if (brr[y+1] <= b && brr[y+1] > a) ans--; 

        swap(arr[a], arr[b]);
        swap(brr[x], brr[y]);

        cout << ans << '\n';
    }

    return 0;
}