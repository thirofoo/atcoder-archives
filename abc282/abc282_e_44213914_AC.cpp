/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/44213914
 * Submitted at: 2023-08-04 00:24:36
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_e
 * Result: AC
 * Execution Time: 143 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll power(ll a, ll b, ll mod){
    // a^b % mod を計算
    ll x = 1, y = a;
    while(b>0){
        if( b & 1ll ) x = ( x * y ) % mod;
        y = ( y * y )%mod;
        b >>= 1;
    }
    return x % mod;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC ~ 最大全域木に言い換え ~
    // 操作を遂行するにあたって...
    // 1. 必ず1回は各ボールに対して操作を行う (連結)
    // 2. 操作が必ず n-1 回で終わる (辺がn-1本存在する)
    // → 木になりそうという発想に至る

    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<T> todo;
    dsu uf(n);
    rep(i,n) {
        for(ll j=i+1;j<n;j++) {
            todo.push( T( (power(a[i],a[j],m)+power(a[j],a[i],m))%m, i, j ) );
        }
    }
    ll ans = 0;
    while( !todo.empty() ) {
        auto [cost, i, j] = todo.top(); todo.pop();
        if( uf.same(i,j) ) continue;
        uf.merge(i,j);
        ans += cost;
    }
    cout << ans << endl;
    
    return 0;
}