/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc315/submissions/44757968
 * Submitted at: 2023-08-19 22:27:50
 * Problem URL: https://atcoder.jp/contests/abc315/tasks/abc315_d
 * Result: AC
 * Execution Time: 340 ms
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

// S が data, F が lazy
using S = ll;
using F = ll;
// operator(作用素)
S op(S a,S b){
    return max(a,b);
}
// 遅延データ反映
S mapping(F f,S x){
    return max(f,x);
}
// 遅延データ作用
F composition(F f,F g){
    return max(f,g);
}
S e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w; cin >> h >> w;
    vector<string> c(h);
    rep(i,h) cin >> c[i];
    vector<vector<ll>> row(h,vector<ll>(26,0)), col(w,vector<ll>(26,0));
    rep(i,h)rep(j,w) row[i][c[i][j]-'a']++;
    rep(i,w)rep(j,h) col[i][c[j][i]-'a']++;

    ll ah = h, aw = w;

    queue<ll> todo_col, todo_row;
    while( true ) {
        // cerr << ah << " " << aw << endl;
        bool f = false;
        rep(i,h) {
            rep(j,26){
                if( row[i][j] == aw && aw != 1 ) {
                    row[i][j] = 0;
                    todo_row.push(j);
                    // rep(k,w) col[k][j]--;
                    // ah--;
                    f = true;
                }
            }
        }
        rep(i,w) {
            rep(j,26){
                if( col[i][j] == ah && ah != 1 ) {
                    col[i][j] = 0;
                    todo_col.push(j);
                    // rep(k,h) row[k][j]--;
                    // aw--;
                    f = true;
                }
            }
        }
        if( !f ) break;
        while( !todo_row.empty() ) {
            ll r = todo_row.front(); todo_row.pop();
            rep(k,w) col[k][r]--;
            ah--;
        }
        while( !todo_col.empty() ) {
            ll r = todo_col.front(); todo_col.pop();
            rep(k,h) row[k][r]--;
            aw--;
        }

        if( ah == 0 || aw == 0 ) break;
    }
    cout << ah*aw << endl;
    
    return 0;
}