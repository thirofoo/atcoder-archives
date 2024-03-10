/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc173/submissions/51134802
 * Submitted at: 2024-03-10 22:38:53
 * Problem URL: https://atcoder.jp/contests/arc173/tasks/arc173_b
 * Result: WA
 * Execution Time: 22 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    dsu uf(n);
    for (int i = 0; i < n; i++) {
        auto [x1, y1] = p[i];
        for (int j = i + 1; j < n; j++) {
            auto [x2, y2] = p[j];
            for (int k = j + 1; k < n; k++) {
                auto [x3, y3] = p[k];
                if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                    uf.merge(i, j);
                    uf.merge(j, k);
                }
            }
        }
    }
    vector g = uf.groups();
    if( g.size() == 1 ) return cout << 0 << endl, 0;

    sort(g.begin(), g.end(), [](vector<int> &a, vector<int> &b) { return a.size() > b.size(); });
    ll ans = 0;
    while( true ) {
        // 多い方から2つ, 2番目に多い方から1つ取り出すのを繰り返す
        // 多いのが1つしかない場合 or 2番目に多いのがない場合は終了
        if( g[0].size() == 1 || g[1].empty() ) break;
        ans++;
        g[0].pop_back();
        g[0].pop_back();
        g[1].pop_back();
        sort(g.begin(), g.end(), [](vector<int> &a, vector<int> &b) { return a.size() > b.size(); });
    }
    if( g[0].size() == 1 ) {
        ll rest = 0;
        for( auto &&i : g ) rest += i.size();
        ans += rest / 3;
    }
    cout << ans << endl;
    
    return 0;
}