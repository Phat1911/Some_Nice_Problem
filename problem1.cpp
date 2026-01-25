#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18 + 1;

struct dat {
    int ai, sl;
};

bool cmp (dat a, dat b) {
    if (a.sl == b.sl) return a.ai < b.ai;
    return a.sl > b.sl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        int subset = 1 << n;
        vector <dat> a;
        for (int i = 0; i < subset; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) cnt++;
                else break;
            }
            a.push_back({i, cnt});
        }
        sort(a.begin(), a.end(), cmp);
        for (auto it : a) cout << it.ai << ' ';
        cout << '\n';
    }
    return 0;
}
