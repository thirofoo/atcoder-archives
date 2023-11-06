/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/47320990
 * Submitted at: 2023-11-06 09:14:36
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_e
 * Result: AC
 * Execution Time: 3066 ms
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
    vector<ll> s(n-1), x(m), delta(n,0);
    map<ll,ll>  mp1, mp2;
    mp1[0]++;
    rep(i,n-1) {
        cin >> s[i];
        delta[i+1] = s[i] - delta[i];
        if( i%2 ) mp1[delta[i+1]]++;
        else mp2[delta[i+1]]++;
    }
    rep(i,m) cin >> x[i];
    ll ans = 0;
    rep(i,n) {
        // i文字目をj番目のラッキーと仮定
        rep(j,m) {
            // delta : 1番目を 0 と固定した時の変化差分
            // ⇒ delta ⇒ delta+1 にすると奇数番目は +1, 偶数番目は-1
            ll cand = 0, a1 = (x[j] - delta[i]) * (i%2 == 0 ? 1 : -1);
            rep(k,m) {
                ll e1 = x[k] - a1;
                ll e2 = x[k] + a1;
                if( mp1.count(e1) ) cand += mp1[e1];
                if( mp2.count(e2) ) cand += mp2[e2];
            }
            ans = max(ans, cand);
        }
    }
    cout << ans << endl;
    
    return 0;
}