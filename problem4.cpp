#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18 + 1;

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    int q;
    cin >> q;    
    while (q--) { 
        int n, k;
        cin >> n >> k;
        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }
        int m = log2(n), h = m + log2(n - 1);
        h = max(h, m + 1ll);
        vector <vector<int>> C(m, vector<int>(m, 0)), sum(m, vector<int>(m, 0));
        for (int i = 1; i < m; i++) {
            C[1][i] = i;
            C[0][i] = 1;
            sum[1][i] = sum[1][i - 1] + i;
        }
        for (int i = 2; i < m; i++) {
            for (int j = i; j < m; j++) {
                C[i][j] = sum[i - 1][j - 1];
                sum[i][j] = sum[i][j - 1] + C[i][j];
            }
        }
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < m; j++) {
        //         cout << C[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        if (k >= h) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = k + 1; j <= h; j++) {
                int tmp = j - i + 1; 
                if (tmp < 1) continue;
                if (tmp <= m && i <= tmp) ans += C[i - 1][tmp - 1];
            }
        }
        cout << ans + (m >= k) << '\n';
    }
    return 0;
}
