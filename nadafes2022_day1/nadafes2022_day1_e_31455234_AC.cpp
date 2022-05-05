/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31455234
 * Submitted at: 2022-05-05 21:54:09
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_e
 * Result: AC
 * Execution Time: 167 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    int n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    dsu uf(n);
    rep(i,m) {
        int u,v; cin >> u >> v;
        u--, v--;
        uf.merge(u,v);
    }
 
    ll ans = accumulate(a.begin(), a.end(), 0LL);
    auto G = uf.groups();
    for (auto g : G) {
        int n = g.size();
        vector<ll> t(n);
        rep(i,n) t[i] = a[g[i]];
        sort(t.begin(), t.end());
 
        if (n & 1) {
            t.emplace_back(1e18);
            n++;
        }
 
        ll mn = 0, cur = 0;
        for (int i = 0; i < n; i += 2) {
            cur += t[i] + t[i + 1];
            mn = min(mn, cur);
        }
        ans -= mn;
    }
    cout << ans << endl;
 
    return 0;
}