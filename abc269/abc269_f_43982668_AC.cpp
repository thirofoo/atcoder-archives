/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/43982668
 * Submitted at: 2023-07-27 11:52:04
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_f
 * Result: AC
 * Execution Time: 370 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,q; cin >> n >> m >> q;

    auto f = [&](ll x1, ll y1, ll x2, ll y2){ 
        // 引数を左上端とした、1つ飛ばしの矩形内和
        if( x1 > x2 || y1 > y2 ) return mint(0);
        mint a1 = (x1-1)*m + y1, n1 = (y2-y1)/2 + 1, n2 = (x2-x1)/2 + 1;
        // cout << x1 << " " << y1 << " : "  << x2 << " " << y2 << endl;
        // cout << a1 << " " << n1 << " " << n2 << endl;
        // cout << ( (a1+n1-1)*n2 + m*(n2-1)*n2 ) * n1 << endl;
        return ( (a1+n1-1)*n2 + m*(n2-1)*n2 ) * n1;
    };

    auto f1 = [&](ll x1, ll y1, ll x2, ll y2) {
        y1 += (x1+y1)%2;
        return f(x1, y1, x2, y2);
    };  
    auto f2 = [&](ll x1, ll y1, ll x2, ll y2) {
        x1++;
        y1 += (x1+y1)%2;
        return f(x1, y1, x2, y2);
    };

    while(q--){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        cout << ( f1(a,c,b,d) + f2(a,c,b,d) ).val() << endl;
    }
    
    return 0;
}