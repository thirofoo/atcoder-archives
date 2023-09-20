/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/45740403
 * Submitted at: 2023-09-20 09:53:00
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_d
 * Result: TLE
 * Execution Time: 2210 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

//約数列挙ver (1,nも含む)
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
    // 約数少ないし行けるだろの精神
    for(ll i=1;i<=n;i++) {
        vector div = divisor(i*i);
        for(auto &&ele:div) {
            if( ele > n || i*i/ele > n ) continue;
            ans++;
        }
    }
    cout << ans << endl;
    
    return 0;
}