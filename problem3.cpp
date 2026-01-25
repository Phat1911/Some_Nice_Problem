#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18 + 1;

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen(".inp", "r", stdin);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        n *= 2;
        int a[n + 1], b[n + 1], c[n + 1];
        for (int i = 1; i <= n / 2; i++) {
            cin >> a[i];
            a[i + n / 2] = a[i];
        }
        for (int i = 1; i <= n / 2; i++) {
            cin >> b[i];
            b[i + n / 2] = b[i];
        }
        for (int i = 1; i <= n / 2; i++) {
            cin >> c[i];
            c[i + n / 2] = c[i];
        }
        int m1 = 0, m2 = 0;
        int pre[n + 1] = {0}, f[n + 1] = {0};
        const int inf = 1e18 + 1;
        // b \ a
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[j] = pre[j - 1];
                if (a[j] < b[i]) f[j]++;
                else f[j] = -inf;
            }
            for (int j = 1; j <= n; j++) pre[j] = f[j];
        }
        for (int i = 1; i <= n; i++) {
            if (f[i] >= n / 2 && i > n / 2) m1++;
            pre[i] = f[i] = 0;
        }
        // c \ b
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f[j] = pre[j - 1];
                if (b[j] < c[i]) f[j]++;
                else f[j] = -inf;
            }
            for (int j = 1; j <= n; j++) pre[j] = f[j];
        }
        for (int i = 1; i <= n; i++) {
            if (f[i] >= n / 2 && i > n / 2) m2++;
        }
        // cout << m1 << ' ' << m2 << '\n';
        cout << m1 * m2 * n / 2 << '\n';
    }
    return 0;
}
