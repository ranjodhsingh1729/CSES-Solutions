#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


int main() {
    int n, k;
    cin >> n >> k;

    int rt = sqrt(n);

    vector<vector <int>> A;
    int cnt = 1;
    vector <int> temp;
    for (int i = 1; i <= n; i++) {
        if (cnt > rt) {
            cnt = 1;
            A.push_back(temp);
            temp.clear();
        }
        temp.push_back(i); cnt++;
    }
    if (!temp.empty()) {
        A.push_back(temp);
    }

    size_t s;
    size_t row = 0, col = 0;
    for (int i = 0; i < n; i++) {
        s = k % (n-i);

        if (s + col < A[row].size()) {
            col += s;
        } else {
            s += col;
            col = 0;
            while (s >= A[row].size()) {
                s -= A[row++].size();
                if (row == A.size())
                    row = 0;
            }
            col = s;
        }

        cout << A[row][col] << ' ';
        A[row].erase(A[row].begin()+col);
    }

    return 0;
}
