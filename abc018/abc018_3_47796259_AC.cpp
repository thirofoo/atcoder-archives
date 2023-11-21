/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc018/submissions/47796259
 * Submitted at: 2023-11-21 13:40:23
 * Problem URL: https://atcoder.jp/contests/abc018/tasks/abc018_3
 * Result: AC
 * Execution Time: 112 ms
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

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll r, c, k; cin >> r >> c >> k;
    vector<vector<char>> s(r+2,vector<char>(c+2,'x')), ns;
    rep(i,r) {
        string str; cin >> str;
        rep(j,c) s[i+1][j+1] = str[j];
    }
    k--;
    while( k-- ) {
        ns = s;
        for(ll i=1; i<=r; i++) {
            for(ll j=1; j<=c; j++) {
                if( s[i][j] == 'x' ) continue;
                bool f = true;
                rep(d,4) f &= (s[i+dx[d]][j+dy[d]] == 'o');
                ns[i][j] = (f ? 'o' : 'x');
            }
        }
        swap(ns,s);
    }
    ll ans = 0;
    rep(i,r+2) rep(j,c+2) ans += (s[i][j] == 'o');
    cout << ans << endl;
    
    return 0;
}