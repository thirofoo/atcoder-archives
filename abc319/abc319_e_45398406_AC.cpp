/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc319/submissions/45398406
 * Submitted at: 2023-09-09 21:58:34
 * Problem URL: https://atcoder.jp/contests/abc319/tasks/abc319_e
 * Result: AC
 * Execution Time: 1754 ms
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
    
    ll n,x,y; cin >> n >> x >> y;
    vector<P> bus;
    rep(i,n-1) {
        ll p, t; cin >> p >> t;
        bus.emplace_back(P(p, t));
    }
    ll q; cin >> q;
    map<vector<ll>, ll> mp;
    // 高々N!のパターンしか無さそう
    while(q--) {
        ll now; cin >> now;
        now += x;
        vector<ll> tmp;
        rep(i,8) tmp.emplace_back(now%(i+1));
        if( mp.count(tmp) ) {
            now += mp[tmp];
            now += y;
        }
        else {
            ll pre = now;
            rep(i,n-1) {
                auto [p, t] = bus[i];
                now = now + ((p-(now%p))%p + p)%p;
                now += t;
            }
            mp[tmp] = now-pre;
            now += y;
        }
        cout << now << endl;
    }
    
    return 0;
}