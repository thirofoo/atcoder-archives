/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc255/submissions/49807614
 * Submitted at: 2024-01-30 16:33:57
 * Problem URL: https://atcoder.jp/contests/abc255/tasks/abc255_f
 * Result: AC
 * Execution Time: 247 ms
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
    
    // 解説 AC
    // point: 木の部分木は木 (当たり前)
    // → 任意の木における対処が見つかると、その部分木に深掘る再起を書けば、その部分木に対しても対処可能
    // ( 木は再起と相性が良すぎる )
    // -1 の条件は「木の根が見つからない」こと

    ll n; cin >> n;
    vector<ll> p(n), l(n), l_idx(n+1);
    rep(i,n) cin >> p[i];
    rep(i,n) {
        cin >> l[i];
        l_idx[l[i]] = i;
    }
    if( p[0] != 1 ) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<ll>> child(n+1, vector<ll>(2,0));
    bool flag = true;
    auto f = [&](auto self, ll l1, ll r1, ll l2, ll r2) -> void {
        if( !flag ) return;
        // cerr << l1 << " " << r1 << " : " << l2 << " " << r2 << endl;

        ll root_idx = l_idx[p[l1]];
        if( root_idx < l2 || r2 <= root_idx ) {
            flag = false;
            return;
        }
        ll ll1, ll2, lr1, lr2, rl1, rr1, rl2, rr2;
        ll1 = l1+1, lr1 = l1+1+(root_idx-l2), ll2 = l2, lr2 = root_idx;
        rl1 = lr1, rr1 = r1, rl2 = root_idx+1, rr2 = r2;
        
        if( lr1-ll1 != 0 ) {
            self(self,ll1,lr1,ll2,lr2);
            child[p[l1]][0] = p[ll1];
        }
        if( rr1-rl1 != 0 ) {
            self(self,rl1,rr1,rl2,rr2);
            child[p[l1]][1] = p[rl1];
        }

        return;
    };
    f(f, 0, n, 0, n);
    if( !flag ) cout << -1 << endl;
    else rep(i,n) cout << child[i+1][0] << " " << child[i+1][1] << endl;
    
    return 0;
}