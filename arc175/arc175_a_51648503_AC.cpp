/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc175/submissions/51648503
 * Submitted at: 2024-03-24 21:26:35
 * Problem URL: https://atcoder.jp/contests/arc175/tasks/arc175_a
 * Result: AC
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
    mint ans1 = 1, ans2 = 1;
    // 右隣が既に持ってるかを管理
    vector<bool> r(n, false);
    rep(i,n) {
        if( s[p[i]] == '?' && r[(p[i]+1)%n] ) ans1 *= 2;
        if( s[p[i]] == 'R' && !r[(p[i]+1)%n] ) r_flag = true;
        r[p[i]] = true;
    }
    // 左隣が既に持ってるかを管理
    vector<bool> l(n, false);
    rep(i,n) {
        if( s[p[i]] == '?' && l[(p[i]+n-1)%n] ) ans2 *= 2;
        if( s[p[i]] == 'L' && !l[(p[i]+n-1)%n] ) l_flag = true;
        l[p[i]] = true;
    }
    mint ans = 0;
    if( !r_flag ) ans += ans1;
    if( !l_flag ) ans += ans2;
    cout << ans.val() << endl;
    
    return 0;
}