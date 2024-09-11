#include <bits/stdc++.h>

#define MAXLEN 100000
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define FIXIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


const int N = 7;
#define isinbounds(x) ((x) >= (0) && (x) < (N))

int ans = 0;
char given[N*N];
bool visited[N][N];


void dfs(int x = 0, int y = 0, int i = 0) {
    if (i == N*N-1 || x == 0 && y == N-1) {
        if (i == N*N-1 && x == 0 && y == N-1)
            ans++;
    } else {
        // Spiral detection
        if ((!isinbounds(x+1) || visited[x+1][y]) && (!isinbounds(x-1) || visited[x-1][y]))
            if (isinbounds(y+1) && !visited[x][y+1] && isinbounds(y-1) && !visited[x][y-1])
                return;
        if ((!isinbounds(y+1) || visited[x][y+1]) && (!isinbounds(y-1) || visited[x][y-1]))
            if (isinbounds(x+1) && !visited[x+1][y] && isinbounds(x-1) && !visited[x-1][y])
                return;


        visited[x][y] = true;
        if (given[i] == 'D' || given[i] == '?') {
            if (isinbounds(y+1) && !visited[x][y+1])
                dfs(x, y+1, i+1);
        }
        if (given[i] == 'U' || given[i] == '?') {
            if (isinbounds(y-1) && !visited[x][y-1])
                dfs(x, y-1, i+1);
        }
        if (given[i] == 'L' || given[i] == '?') {
            if (isinbounds(x-1) && !visited[x-1][y])
                dfs(x-1, y, i+1);

        }
        if (given[i] == 'R' || given[i] == '?') {
            if (isinbounds(x+1) && !visited[x+1][y])
                dfs(x+1, y, i+1);
        }
        visited[x][y] = false;

    }
}


int main() {
    cin >> given;

    dfs();

    cout << ans << '\n';

    return 0;
}