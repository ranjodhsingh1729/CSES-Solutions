#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, tmp;
    vector <int> A;
    vector <int> :: iterator itr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        itr = upper_bound(A.begin(), A.end(), tmp);
        if (itr != A.end()) {
            A[itr-A.begin()] = tmp;
        } else {
            A.push_back(tmp);
        }
    }

    cout << A.size() << '\n';

    return 0;
}