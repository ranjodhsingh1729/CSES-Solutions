#include <bits/stdc++.h>

#define MAXLEN 100000

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    if (n != 2 && n != 3) {
        for (int i = 2; i <= n; i+=2) {
            cout << i << ' ';
        }

        for (int i = 1; i <= n; i+=2) {
            cout << i << ' ';
        }
    } else {
        cout << "NO SOLUTION";
    }

    cout << '\n';


    return 0;
}