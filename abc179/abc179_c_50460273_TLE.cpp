/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/50460273
 * Submitted at: 2024-02-20 09:04:42
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_c
 * Result: TLE
 * Execution Time: 2032 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll ans = 0;
    for(ll c=1; c<n; c++) {
        vector<ll> div = divisor(n-c);
        ans += div.size();
    }
    cout << ans << endl;
    
    return 0;
}