/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44040105
 * Submitted at: 2023-07-29 21:07:39
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_b
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    rep(i,n-8){
        rep(j,m-8){
            bool f = true;
            rep(k,3){
                rep(l,3){
                    f &= (s[i+k][j+l] == '#');
                    f &= (s[i+6+k][j+6+l] == '#');
                }
            }
            rep(k,4) f &= (s[i+3][j+k] == '.');
            rep(k,4) f &= (s[i+k][j+3] == '.');
            rep(k,4) f &= (s[i+5][j+5+k] == '.');
            rep(k,4) f &= (s[i+5+k][j+5] == '.');
            if( f ) cout << i+1 << " " << j+1 << endl;
        }
    }
    
    return 0;
}