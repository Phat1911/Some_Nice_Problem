#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = 1e18 + 1;

struct dat {
    int a, b, c;
};

dat proc (int x, int y, vector <int> ids) {
    int nx = x, mx = 0;
    vector <int> mark (31, 0);
    for (int id: ids) nx -= (1 << id), mark[id] = 1, mx = max(mx, id);

    int tmp = 0;
    for (int i = 0; i < mx; i++) {
        if (((y >> i) & 1) == 0 && ((x >> i) & 1) == 0) {
            nx += (1 << i); 
        }
    }
    int tmp1 = 0, y1 = 0, f = -1;
    for (int i = mx + 1; i <= 31; i++) {
        if (((y >> i) & 1) == 0 && ((x >> i) & 1) == 0) {
            f = i;
            break;
        }
    }
    if (f == -1) {
        tmp1 = y1 = inf;
    } else {
        tmp1 = (1 << f);
        y1 = y;
        for (int i = f; i <= 31; i++) if (((x >> i) & 1)) tmp1 += (1 << i);
    }
    // cout << y1 << ' ' << tmp1 << '\n';
    if (abs(x - nx) < abs(x - tmp1) + abs(y - y1)) {
        return {nx, y, abs(x - nx)};
    }
    return {tmp1, y1, abs(x - tmp1) + abs(y - y1)};
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".inp", "r", stdin);
    int q;
    cin >> q;    
    while (q--) { 
        int x, y;
        cin >> x >> y;
        vector <int> ids;
        for (int i = 0; i <= 30; i++) {
            if (((x >> i) & 1) && ((y >> i) & 1)) {
                ids.push_back(i);
            }
        }
        dat a1 = proc(x, y, ids), a2 = proc(y, x, ids);
        if (a1.c < a2.c) {
            cout << a1.a << ' ' << a1.b << '\n';
        } else {
            cout << a2.b << ' ' << a2.a << '\n';
        }
        
        // int mn = inf, x1, x2;
        // for (int i = 1; i <= 1000; i++) {
        //     for (int j = 1; j <= 1000; j++) {
        //         int tmp = abs(x - i) + abs(y - j);
        //         if (mn > tmp && (i & j) == 0) {
        //             mn = tmp;
        //             x1 = i; x2 = j;
        //         }
        //     }
        // }
        // cout << x1 << ' ' << x2 << '\n';
    }

    return 0;
}
