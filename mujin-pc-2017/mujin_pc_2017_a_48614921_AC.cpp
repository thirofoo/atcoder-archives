/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/mujin-pc-2017/submissions/48614921
 * Submitted at: 2023-12-17 19:04:45
 * Problem URL: https://atcoder.jp/contests/mujin-pc-2017/tasks/mujin_pc_2017_a
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];

    vector<mint> fact(n+1,1), r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    mint ans = fact[n], past = 1;
    ll now = 1, cnt = 0;
    rep(i,n) {
        if( x[i] < now ) {
            ans -= (n-i-1) * fact[n-1-cnt] * past;
            past *= i+1-cnt;
            cnt++;
        }
        else now += 2;
    }
    cout << ans.val() << endl;
    
    return 0;
}