/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/50278144
 * Submitted at: 2024-02-15 11:00:20
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_f
 * Result: AC
 * Execution Time: 211 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    ll n = r2+c2+5;
    vector<mint> kaizyo(n+1,0);
    kaizyo[0] = 1;
    for(ll i=1;i<=n;i++)kaizyo[i] = kaizyo[i-1]*i;
    vector<mint> fact(n+1,1), r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };
    cout << (nCr(r2+c2+2,r2+1) - nCr(r2+1+c1,c1) - nCr(r1+c2+1,r1) + nCr(r1+c1,r1)).val() << endl;
    
    return 0;
}