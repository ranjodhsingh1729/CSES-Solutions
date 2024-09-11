#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int ans = 0;
bool board[8][8] = { false }, input[8][8] = { true };


bool is_legal(int x, int y, int n = 8) {
    bool ans = true;

    if (input[x][y])
        ans = false;

    for (int i = 0; i < n; i++)
        if (board[x][i] || board[i][y])
            ans = false;
    for (int i = 0; x-i >= 0 && y-i >= 0; i++)
        if (board[x-i][y-i])
            ans = false;
    for (int i = 0; x-i >= 0 && y+i < n; i++)
        if (board[x-i][y+i])
            ans = false;

    return ans;
}

bool final_check(int n = 8) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] && input[i][j])
                return false;
    return true;
}

void dfs(int i = 0, int n = 8) {
    if (i == n) {
        ans++;
    } else {
        for (int j = 0; j < n; j++) {
            if (is_legal(i, j, n)) {
                board[i][j] = true;
                dfs(i+1);
                board[i][j] = false;
            }
        }
    }
}


int main() {
    FIXIO;

    char f;
    int n = 8;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> f;
            input[i][j] = (f == '*' ? true : false);
        }
    }

    dfs();
    cout << ans << '\n';

    return 0;
}