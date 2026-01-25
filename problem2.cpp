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
        int n, x, y;
        cin >> n >> x >> y;
        string s; cin >> s;
        int c[n + 1];
        for (int i = 1; i <= n; i++) cin >> c[i];
        pair <int, int> check;
        int a[n + 1], b[n + 1];
        int sa = 0, sb = 0, mxa = 0, mxb = 0, mount = 0;
        for (int i = 1; i <= n; i++) {
            int l = c[i] / 2, r = c[i] - l;
            if (l == r) l--, r++;
            mount += (r - l == 2);
            if (s[i - 1] == '0') sa += r, sb += l, mxb += l, check.first = 1;
            else sa += l, sb += r, mxa += l, check.second = 1;
        }
        // cout << sa << ' ' << sb  << ' ';
        if (sa <= x && sb <= y) {
            if (check.first && check.second) cout << "YES";
            else if (check.first) {
                if (x - sa + mount >= y - sb) cout << "YES";
                else cout << "NO";
            } else {
                if (x - sa <= y - sb + mount) cout << "YES";
                else cout << "NO";
            }
        }
        else if (sa > x && sb > y) {
            cout << "NO";
        } else if (sa > x) {
            // cout << mxa << ' ';
            if (check.second && mxa >= sa - x && sb + sa - x <= y) cout << "YES";
            else cout << "NO";
        } else if (sb > y) {
            if (check.first && mxb >= sb - y && sa + sb - y <= x) cout << "YES";
            else cout << "NO";
        }
        cout << '\n';
    }
    return 0;
}
