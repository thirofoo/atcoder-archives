/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc324/submissions/47610699
 * Submitted at: 2023-11-16 13:47:32
 * Problem URL: https://atcoder.jp/contests/abc324/tasks/abc324_d
 * Result: WA
 * Execution Time: 90 ms
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
    vector<ll> cnt(10,0), cnt2;
    rep(i,n) cnt[s[i]-'0']++;
    ll ans = 0;
    for(ll i=1; i*i<=1e14; i++) {
        string tmp = to_string(i*i);
        if( tmp.size() > n ) break;
        cnt2.assign(10,0);
        rep(j,tmp.size()) cnt2[tmp[j]-'0']++;
        cnt2[0] += n-tmp.size();
        // if( cnt == cnt2 ) cerr << tmp << endl;
        ans += (cnt == cnt2);
    }
    cout << ans << endl;
    
    return 0;
}