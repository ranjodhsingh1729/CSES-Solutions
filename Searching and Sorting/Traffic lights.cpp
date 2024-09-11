#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    set <int> A;
    set <int> :: iterator itr;

    int x, n, tmp;
    int arr[2*MAXLEN];

    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr[i] = tmp;
        A.insert(tmp);
    }

    int ans = *A.begin() - 0;
    for (auto i = next(A.begin()); i != A.end(); i++) {
        tmp = *i - *prev(i);
        ans = max(ans, tmp);
    }
    ans = max(ans, x - *A.rbegin());

    int k = 0, brr[2*MAXLEN];

    brr[k++] = ans;
    for (int i = n-1; i >= 0; i--) {
        itr = A.lower_bound(arr[i]);

        if (A.size() == 1) {
            tmp = x;
        } else if (itr == A.begin()) {
            tmp = *next(itr) - 0;
        } else if (itr == prev(A.end())) {
            tmp = x - *prev(itr);
        } else {
            tmp = *next(itr) - *prev(itr);
        }

        if (tmp > ans) {
            ans = tmp;
        }
        brr[k++] = ans;

        A.erase(itr);
    }

    for (int i = n-1; i >= 0; i--) {
        cout << brr[i] << ' ';
    }
    cout << '\n';

    return 0;
}