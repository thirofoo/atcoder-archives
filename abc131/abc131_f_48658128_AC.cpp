/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc131/submissions/48658128
 * Submitted at: 2023-12-19 19:32:15
 * Problem URL: https://atcoder.jp/contests/abc131/tasks/abc131_f
 * Result: AC
 * Execution Time: 77 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 初手でL型が成立してる部分のみが答え候補っぽい
    // ⇒ 初手で□になってる部分を後で引く
    
    ll n; cin >> n;
    vector<vector<P>> px(100005), py(100005);
    vector<P> v;
    rep(i,n) {
        ll x, y; cin >> x >> y;
        px[y].emplace_back(P(x,i));
        py[x].emplace_back(P(y,i));
        v.emplace_back(P(x,y));
    }
    dsu uf(n);
    rep(i,100005) {
        rep(j,(ll)py[i].size()-1) uf.merge(py[i][j+1].second, py[i][j].second);
        rep(j,(ll)px[i].size()-1) uf.merge(px[i][j+1].second, px[i][j].second);
    }
    vector g = uf.groups();
    ll ans = 0;
    for(auto group:g) {
        set<ll> sx, sy;
        for(auto idx:group) {
            auto [x,y] = v[idx];
            sx.insert(x);
            sy.insert(y);
        }
        ans += sx.size()*sy.size() - group.size();
    }
    cout << ans << endl;
    
    return 0;
}