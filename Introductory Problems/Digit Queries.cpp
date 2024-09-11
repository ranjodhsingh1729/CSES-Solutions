#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    // FIXIO;

    int q;
    cin >> q;

    ll k;

    ll i, num;
    while (q--) {
        cin >> k;
        for (i = 1; k > 9*i*powl(10, i-1); i++)
            k -= 9*i*powl(10, i-1);
        
        k--;
        num = powl(10, i-1) + k/i;
        cout << to_string(num)[k%i] << '\n';
    }

    return 0;
}