/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/45945626
 * Submitted at: 2023-09-25 22:09:57
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_f
 * Result: AC
 * Execution Time: 291 ms
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
    
    // wolfram alpha 典型
    ll r1, c1, r2 ,c2; cin >> r1 >> c1 >> r2 >> c2;
    r1++, c1++, r2++, c2++;
    vector<mint> fact(3000000,1);
    vector<mint> r_fact(3000000,1);
    for(int i=1;i<=3000000;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };
    mint ans = nCr(r2+c2,c2) - nCr(r2+c1-1,c1-1) - nCr(r1-1+c2,c2) + nCr(r1-1+c1-1,c1-1);
    cout << ans.val() << endl;
    
    return 0;
}

