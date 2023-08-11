/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc239/submissions/44446787
 * Submitted at: 2023-08-11 10:12:26
 * Problem URL: https://atcoder.jp/contests/abc239/tasks/abc239_e
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    vector<ll> x(n);
    vector<vector<ll>> Graph(n);
    rep(i,n) cin >> x[i];
    rep(i,n-1) {
        ll a,b; cin >> a >> b;
        a--; b--;
        Graph[a].emplace_back(b);
        Graph[b].emplace_back(a);
    }

    vector<multiset<ll>> st(n);
    auto dfs = [&](auto self, ll now, ll pre) -> void {
        for(auto to:Graph[now]) {
            if( to == pre ) continue;
            self(self,to,now);
            for(auto ele:st[to]) st[now].insert(ele);
        }
        st[now].insert(x[now]);
        while( st.size() > 20 ) st.erase(st.begin());
        return;
    };
    dfs(dfs,0,-1);

    // rep(i,n) {
    //     for(auto ele:st[i]) cout << ele << " ";
    //     cout << endl;
    // }
    // cout << endl;

    while( q-- ) {
        ll v,k; cin >> v >> k;
        v--;
        auto itr = st[v].end();
        rep(i,k) itr--;
        cout << *itr << endl;
    }
    
    return 0;
}