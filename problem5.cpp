#include <bits/stdc++.h>
using namespace std;

bool check (int n, int a[]) {
    for (int i = 2; i <= n; i++) if ((a[i] ^ 1) == n - 1) {
        return true;
    }
    return false;
}

signed main()
{
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int ans[n+1] = {0};
        ans[n] = 1;
        for (int i = 2; i < n - 1; i += 2) {
            ans[i] = i + 1;
            ans[i + 1] = i;
        }
        if (n & 1) {
            ans[1] = n - 1;
            ans[n - 1] = n;
            if (!check(n, ans)) {
                cout << -1 << '\n';
                continue;
            }
        } else {
            int f = 0;
            for (int i = 2; i <= n; i++) {
                int pos = ans[i] ^ n;
                if (pos < i) {
                    ans[1] = ans[pos];
                    ans[pos] = n;
                    f = 1;
                    break;
                }
            }
            if (!f) {
                cout << -1 << '\n';
                continue;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
