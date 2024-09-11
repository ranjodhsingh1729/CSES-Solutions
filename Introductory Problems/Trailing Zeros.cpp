#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    int x = 0;

    for (int i = 5; i <= n; i*=5) {
        x += n/i;
    }

    cout << x << '\n';

    return 0;
}