/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc329/submissions/47682773
 * Submitted at: 2023-11-18 21:04:52
 * Problem URL: https://atcoder.jp/contests/abc329/tasks/abc329_c
 * Result: AC
 * Execution Time: 2 ms
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
    
    ll n; string s; cin >> n >> s;
    vector<ll> cnt(26,0);
    ll now = 0; char ch = s[0];
    rep(i,n) {
        if( ch == s[i] ) now++;
        else {
            cnt[ch-'a'] = max(cnt[ch-'a'], now);
            now = 1; ch = s[i];
        }
    }
    cnt[ch-'a'] = max(cnt[ch-'a'], now);
    ll ans = 0;
    rep(i,26) ans += cnt[i];
    cout << ans << endl;
    
    return 0;
}