/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc313/submissions/45696415
 * Submitted at: 2023-09-18 12:50:36
 * Problem URL: https://atcoder.jp/contests/abc313/tasks/abc313_e
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n; string s; cin >> n >> s;
    rep(i,n-1)  {
        if( s[i] >= '2' && s[i+1] >= '2' ) {
            cout << -1 << endl;
            return 0;
        }
    }
    mint ans = 0;
    while( !s.empty() ) {
        mint a1 = 0, d = 1;
        if( s.back() >= '2' ) {
            d = s.back() - '0';
            s.pop_back();
            ans++;
        }
        while( !s.empty() && s.back() == '1' ) {
            s.pop_back();
            a1++;
        }
        ans += a1 + ( a1 == 0 ? 0 : (d-1)*ans );
    }
    cout << (ans-1).val() << endl;
    
    return 0;
}

