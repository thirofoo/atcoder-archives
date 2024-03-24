/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc175/submissions/51651466
 * Submitted at: 2024-03-24 21:57:02
 * Problem URL: https://atcoder.jp/contests/arc175/tasks/arc175_b
 * Result: WA
 * Execution Time: 11 ms
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
    
    ll n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    ll l_cnt = 0, r_cnt = 0;
    rep(i,s.size()) {
        if( s[i] == '(' ) l_cnt++;
        else r_cnt++;
    }
    ll ans = 0;
    ll cnt = l_cnt - r_cnt;
    if( cnt > 0 ) {
        // 右端から ( ⇒ ) に変える
        for(ll i=s.size()-1; i>=0; i--) {
            if( cnt <= 0 ) break;
            if( s[i] == '(' ) {
                s[i] = ')';
                ans += b;
                cnt -= 2;
            }
        }
    }
    else if( cnt < 0 ) {
        // 左端から ) ⇒ ( に変える
        for(ll i=0; i<s.size(); i++) {
            if( cnt >= 0 ) break;
            if( s[i] == ')' ) {
                s[i] = '(';
                ans += b;
                cnt += 2;
            }
        }
    }
    vector<ll> rui(n+1, 0);
    ll min_cnt = 0;
    rep(i,n) {
        if( s[i] == '(' ) rui[i+1] = rui[i] + 1;
        else rui[i+1] = rui[i] - 1;
        min_cnt = min(min_cnt, rui[i+1]);
    }
    min_cnt = abs(min_cnt);
    // cerr << s << endl;
    // cerr << ans << " " << min_cnt << endl;
    ll mini = min(a, 2*b);
    ans += mini * (ll)( (min_cnt+1) / 2 );
    cout << ans << endl;
    
    return 0;
}
