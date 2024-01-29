/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/49797723
 * Submitted at: 2024-01-30 03:02:56
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_d
 * Result: WA
 * Execution Time: 2208 ms
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
    
    ll n, m; cin >> n >> m;
    vector<string> s(n);
    set<string> st;
    rep(i,n) cin >> s[i];
    rep(i,m) {
        string t; cin >> t;
        st.insert(t);
    }
    vector<ll> p(n,0);
    string ans = "";
    bool f = false;
    auto dfs = [&](auto self, string now, ll idx) -> void {
        if( now.size() > 16 || ans.size() != 0 ) return;
        // cerr << now << endl;
        if( idx == n ) {
            if( !st.count(now) ) ans = now;
            return;
        }
        while( now.size() <= 16 ) {
            now += "_";
            self(self, now+s[p[idx]], idx+1);
        }
        return;
    };
    
    iota(p.begin(), p.end(), 0);
    do {
        dfs(dfs, s[p[0]], 1);
        if( ans.size() != 0 )  {
            cout << ans << endl;
            return 0;
        }
    } while(next_permutation(p.begin(), p.end()));
    cout << -1 << endl;

    return 0;
}