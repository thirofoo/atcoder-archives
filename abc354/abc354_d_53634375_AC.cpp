/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53634375
 * Submitted at: 2024-05-18 22:36:34
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_d
 * Result: AC
 * Execution Time: 1 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a, b, c, d; cin >> a >> b >> c >> d;
    // 4 通り場合分け
    ll col1 = 0, col2 = 0, col3 = 0, col4 = 0;
    vector<ll> col;
    ll nb = ( b >= 0 ? b+1 : b );
    ll nd = ( d >= 0 ? d : d-1 );

    col1 += ( (nd/2) - (nb/2) ) * 3;
    col1 += (d%2 + 2)%2 * 2;
    col1 += (b%2 + 2)%2;
    
    col2 += ( (nd/2) - (nb/2) ) * 3;
    col2 += (d%2 + 2)%2;
    col2 += (b%2 + 2)%2 * 2;

    col3 += ( (nd/2) - (nb/2) );
    col3 += (b%2 + 2)%2;

    col4 += ( (nd/2) - (nb/2) );
    col4 += (d%2 + 2)%2;

    col.emplace_back(col1);
    col.emplace_back(col2);
    col.emplace_back(col3);
    col.emplace_back(col4);

    ll ans = 0;
    ans += ((c-a)/4)*(col1 + col2 + col3 + col4);
    ll idx1 = (a%4 + 4)%4;
    ll idx2 = (c%4 + 4)%4;
    // cerr << idx1 << ' ' << idx2 << endl;
    // cerr << col1 << ' ' << col2 << ' ' << col3 << ' ' << col4 << endl;
    while( idx1 != idx2 ) {
        ans += col[idx1];
        idx1++;
        idx1 %= 4;
    }
    cout << ans << '\n';
    
    return 0;
}