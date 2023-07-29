/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc064/submissions/44019191
 * Submitted at: 2023-07-29 09:51:16
 * Problem URL: https://atcoder.jp/contests/abc064/tasks/abc064_d
 * Result: AC
 * Execution Time: 8 ms
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
    
    // (,) の数確認　→ (は左に、)は右に付加すべき
    ll n; string s; cin >> n >> s;
    vector<ll> r1(n+1,0), r2(n+1,0);
    ll cnt1 = 0, cnt2 = 0;
    rep(i,n) {
        r1[i+1] += (s[i] == '(' ? -1 : 1);
        r1[i+1] += r1[i];
        cnt1 = max(cnt1, r1[i+1]);
    }
    reverse(s.begin(),s.end());
    rep(i,n) {
        r2[i+1] += (s[i] == '(' ? 1 : -1);
        r2[i+1] += r2[i];
        cnt2 = max(cnt2, r2[i+1]);
    }
    reverse(s.begin(),s.end());
    string ans_pre = "";
    rep(i,cnt1) ans_pre += "(";
    rep(i,cnt2) s += ")";
    cout << ans_pre << s << endl;
    
    return 0;
}