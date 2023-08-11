/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/44446256
 * Submitted at: 2023-08-11 09:37:26
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_c
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    
    ll ans = 1e16;
    rep(i,10) {
        ll cand = 0;
        vector<ll> cnt(10 ,0);
        rep(j,n)rep(k,10) if( s[j][k]-'0' == i ) cnt[k]++;
        rep(j,10) cand = max(cand, (cnt[j]-1)*10 + j );
        ans = min(ans,cand);
    }
    cout << ans << endl;
    
    return 0;
}