/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc175/submissions/51647246
 * Submitted at: 2024-03-24 21:12:53
 * Problem URL: https://atcoder.jp/contests/arc175/tasks/arc175_a
 * Result: WA
 * Execution Time: 14 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    string s; cin >> s;
    bool r_flag = false, l_flag = false;
    rep(i,n) {
        if(s[i] == 'R') r_flag = true;
        if(s[i] == 'L') l_flag = true;
    }
    if( l_flag && r_flag ) return cout << 0 << '\n', 0;
    if( l_flag ) {
        mint ans = 1;
        // 右隣が既に持ってるかを管理
        vector<bool> r(n, false);
        rep(i,n) {
            if( s[i] == '?' && r[(p[i]+1)%n] ) ans *= 2;
            r[p[i]] = true;
        }
        cout << ans.val() << '\n';
    }
    else if ( r_flag ) {
        mint ans = 1;
        // 左隣が既に持ってるかを管理
        vector<bool> l(n, false);
        rep(i,n) {
            if( s[i] == '?' && l[(p[i]+n-1)%n] ) ans *= 2;
            l[p[i]] = true;
        }
        cout << ans.val() << '\n';
    }
    else {
        mint ans1 = 1, ans2 = 1;
        // 右隣が既に持ってるかを管理
        vector<bool> r(n, false);
        rep(i,n) {
            if( s[i] == '?' && r[(p[i]+1)%n] ) ans1 *= 2;
            r[p[i]] = true;
        }
        // 左隣が既に持ってるかを管理
        vector<bool> l(n, false);
        rep(i,n) {
            if( s[i] == '?' && l[(p[i]+n-1)%n] ) ans2 *= 2;
            l[p[i]] = true;
        }
        cout << (ans1 + ans2).val() << '\n';
    }
    
    return 0;
}