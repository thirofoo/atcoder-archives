/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc311/submissions/43832274
 * Submitted at: 2023-07-22 21:04:52
 * Problem URL: https://atcoder.jp/contests/abc311/tasks/abc311_b
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,d; cin >> n >> d;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll ans = 0;
    rep(i,d){
        ll now = i;
        while( now < d ){
            bool f = true;
            rep(j,n) f &= (s[j][now] == 'o');
            if( !f ) break;
            now++;
        }
        ans = max(ans, now-i);
    }
    cout << ans << endl;
    
    return 0;
}