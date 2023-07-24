/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc132/submissions/43936070
 * Submitted at: 2023-07-24 23:49:33
 * Problem URL: https://atcoder.jp/contests/abc132/tasks/abc132_d
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, blue; cin >> n >> blue;
    ll red = n - blue;

    vector<mint> fact(n+1,1);
    vector<mint> r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto f = [&](ll num){
        return (fact[red+1] *  r_fact[num] * r_fact[red+1-num]) * (fact[blue-1] * r_fact[blue-num] * r_fact[num-1]);
    };
    mint ans = 0;
    for(ll i=1;i<=blue;i++) {
        if( red + 1 < i ) {
            cout << 0 << endl;
            continue;
        }
        cout << f(i).val() << endl;
    }
    
    return 0;
}