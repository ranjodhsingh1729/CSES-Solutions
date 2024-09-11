#include <bits/stdc++.h>

#define MAXLEN 100000
using namespace std;
typedef long long ll;


void grey_code(int n, string x = "") {
    if (n) {
        x.push_back('0');
        grey_code(n-1, x);
        x.pop_back();
        x.push_back('1');
        grey_code(n-1, x);
    } else {
        for (int i = n-1; i > 0; i--) {
            x[i] = (x[i] == x[i-1] ? '0' : '1');
        }
        cout << x << '\n';
    }
}

int main() {
    int n;
    cin >> n;

    grey_code(n);

    return 0;
}