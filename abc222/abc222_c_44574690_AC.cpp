/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc222/submissions/44574690
 * Submitted at: 2023-08-14 09:24:10
 * Problem URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
 * Result: AC
 * Execution Time: 6 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vector<string> a(2*n,string(m,0));
    rep(i,2*n) cin >> a[i];
    priority_queue<P> todo, stock;
    rep(i,2*n) todo.push(P(0,-i));
    rep(i,m) {
        while( !todo.empty() ) {
            auto [p1,idx1] = todo.top(); todo.pop();    
            auto [p2,idx2] = todo.top(); todo.pop();    
            idx1 *= -1, idx2 *= -1;    
            if( (a[idx1][i] == 'P' && a[idx2][i] == 'G') || (a[idx1][i] == 'G' && a[idx2][i] == 'C') || (a[idx1][i] == 'C' && a[idx2][i] == 'P') ) {
                p1++;
            }
            else if( (a[idx2][i] == 'P' && a[idx1][i] == 'G') || (a[idx2][i] == 'G' && a[idx1][i] == 'C') || (a[idx2][i] == 'C' && a[idx1][i] == 'P') ) {
                p2++;
            }
            stock.push(P(p1,-idx1));
            stock.push(P(p2,-idx2));
        }
        swap(stock,todo);
    }
    while( !todo.empty() ) {
        auto [p,idx] = todo.top(); todo.pop();
        idx *= -1;
        cout << idx+1 << endl;
    }
    
    return 0;
}