#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, m, tmp;
    cin >> n >> m;
    multiset <int> tickets;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        tickets.insert(-tmp);
    }

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        auto ptr = tickets.lower_bound(-tmp);

        if (ptr == tickets.end()) {
            cout << -1 << '\n';
        } else {
            cout << -(*ptr) << '\n';
            tickets.erase(ptr);
        }
    }

    
    return 0;
}