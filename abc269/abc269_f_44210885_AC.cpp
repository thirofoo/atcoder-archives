/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/44210885
 * Submitted at: 2023-08-03 22:15:01
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_f
 * Result: AC
 * Execution Time: 449 ms
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
    // 2つのまだら模様に分けて等差数列
    auto f = [&](ll x1, ll y1, ll x2, ll y2) {
        if( x1 > x2 || y1 > y2 ) return mint(0);
        mint res = 0, row_d = 2, col_d = 2*m;
        mint row_n = (y2-y1)/2 + 1, col_n = (x2-x1)/2 + 1;
        res += col_n * ( row_n * (-2*m + 2*y1 + (row_n-1)*row_d ) ) / 2;
        res += col_n * row_n * ( 2*x1*m + (col_n-1)*col_d ) / 2;
        return res;
    };
    auto f_total = [&](ll x1, ll y1, ll x2, ll y2) {
        if( (x1+y1)%2 == 1 ) {
            // cout << f(x1+1,y1,x2,y2).val() << " " << f(x1,y1+1,x2,y2).val() << endl;
            return f(x1+1,y1,x2,y2) + f(x1,y1+1,x2,y2);
        }
        else {
            // cout << f(x1,y1,x2,y2).val() << " " << f(x1+1,y1+1,x2,y2).val() << endl;
            return f(x1,y1,x2,y2) + f(x1+1,y1+1,x2,y2);
        }
    };

    rep(i,q) {
        ll a,b,c,d; cin >> a >> b >> c >> d;
        cout << f_total(a,c,b,d).val() << endl;
    }
    
    return 0;
}