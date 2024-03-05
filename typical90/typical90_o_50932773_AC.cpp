/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50932773
 * Submitted at: 2024-03-05 23:46:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_o
 * Result: AC
 * Execution Time: 20 ms
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
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    // 解説 AC : ボールの個数全探索 
    // ⇒ 差が 1 上がると必要なスペースがボールの個数分だけ増える
    // ⇒ 差が調和級数に帰着
    vector<mint> fact(n+1,1), r_fact(n+1,1);
    for(int i=1; i<=n; i++) {
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r) {return fact[n] * r_fact[r] * r_fact[n-r];};
    vector<mint> ans(n+1,0);
    reps(ball,1,n+1) reps(diff,1,n+1) {
        // rest : n - (ball-1 個の空き) * (1空きに diff-1 個スペース)
        ll rest = n - (ball+(ball-1)*(diff-1));
        if( rest < 0 ) break; // ここで調和級数に帰着
        // 両端含めた ball+1 個のスペースへの rest の割り当て方
        // ⇒ 重複組合せ
        ans[diff] += nCr(rest+ball,ball);
    }
    reps(i,1,n+1) cout << ans[i].val() << " ";
    cout << endl;
    
    return 0;
}