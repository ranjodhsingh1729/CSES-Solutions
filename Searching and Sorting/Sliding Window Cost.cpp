#include <bits/stdc++.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;
typedef long long ll;
typedef array<int, 3> triple;
const int MAXN = 2e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;


struct FenwickTree {
    int n;
    vector <ll> BIT;

    FenwickTree(int n) {
        this->n = n;
        BIT.assign(n, 0);
    }

    FenwickTree(const vector <ll> &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++) {
            add(i, a[i]);
        }
    }

    ll sum(int r) {
        ll res = 0;
        for ( ; r >= 0; r = (r & (r + 1)) - 1) {
            res += BIT[r];
        }
        return res;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l-1);
    }

    void add(int idx, ll delta) {
        for ( ; idx < n; idx = idx | (idx + 1)) {
            BIT[idx] += delta;
        }
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    int arr[MAXN];
    map <ll, int> comp;
    map <int, ll> decomp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        comp[arr[i]] = 0;
    }

    int index = 0;
    for (auto &i: comp) {
        i.second = index++;
        decomp[i.second] = i.first;
    }

    int mid = (k-1)/2+1;
    int lmid = k/2-!(k&1), rmid = k/2;
    FenwickTree fw(MAXN);

    ll cost;
    int prev, curr, diff;
    for (int i = 0; i < n; i++) {
        fw.add(comp[arr[i]], 1);

        if (i >= k) fw.add(comp[arr[i-k]], -1);
        if (i >= k-1) {
            ll tmp1, tmp2, ans = -1;
            int l = 0, h = 2e5, p;
            while (l <= h) {
                p = (l+h)/2;
                tmp1 = fw.sum(p-1);
                tmp2 = fw.sum(p);

                if (tmp1 < mid && mid <= tmp2) {
                    ans = p; break;
                } else if (mid <= tmp1) {
                    h = p-1;
                } else {
                    l = p+1;
                }
            }
            curr = decomp[ans];
            if (i == k-1) {
                cost = 0;
                for (int j = 0; j < k; j++) {
                    cost += abs(curr-arr[j]);
                }
            } else {
                cost -= abs(arr[i-k]-prev);
                cost += abs(arr[i]-prev);

                diff = curr-prev;
                cost += lmid*diff;
                cost -= rmid*diff;

                cost -= abs(diff);
            }

            cout << cost << ' ';

            prev = curr;
        }
    }

    cout << '\n';

    return 0;
}