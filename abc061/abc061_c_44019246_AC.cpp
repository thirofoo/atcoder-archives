/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc061/submissions/44019246
 * Submitted at: 2023-07-29 09:55:30
 * Problem URL: https://atcoder.jp/contests/abc061/tasks/abc061_c
 * Result: AC
 * Execution Time: 33 ms
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
    
    ll n,k; cin >> n >> k;
    vector<P> num;
    rep(i,n) {
        ll a,b; cin >> a >> b;
        num.emplace_back(P(a,b));
    }
    sort(num.begin(), num.end());
    ll cnt = 0;
    for(auto [a,b]:num){
        cnt += b;
        if( cnt >= k ) {
            cout << a << endl;
            return 0;
        }
    }
    
    return 0;
}