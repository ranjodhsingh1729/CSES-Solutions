#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, tmp;
    multiset <int> A;
    multiset <int> :: iterator it;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        it = A.upper_bound(tmp);
        if (it != A.end())
            A.erase(it);
        A.insert(tmp);
    }

    cout << A.size() << '\n';

    return 0;
}