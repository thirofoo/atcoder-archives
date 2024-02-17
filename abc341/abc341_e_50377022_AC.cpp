/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc341/submissions/50377022
 * Submitted at: 2024-02-17 22:03:54
 * Problem URL: https://atcoder.jp/contests/abc341/tasks/abc341_e
 * Result: AC
 * Execution Time: 783 ms
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

// Sはデータ。区間取得の結果の型
struct S{
    long long value;
    int size;
};

// F は lazy、つまり操作（写像）を表す値の型
using F = long long;
// using F = bool;

// 区間取得をどのような演算で行うかを定義
S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }

// 区間取得演算 op の単位元
S e(){ return {0, 0}; }

// 操作 f を各ノードが持つ data の値 x に対して作用させる関数
S mapping(F f, S x){ 
  // return {x.value + f*x.size, x.size}; 
  
  // 操作は1足してmod2しかない（が、2回重なると0なので0で伝播することがあるのでif分岐必要）
  // 途中のブロックも考えると、サイズ分反転する
  if(f){ // 必要！
    x.value = x.size - x.value; // ********************  
  }
  return x;
}
// 既にこれまでの操作を溜めている lazy に対して、さらに新しい操作を追加する関数
F composition(F f, F g){ 
  // return f+g;
  return f^g; // ***************
}
F id(){ return 0; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    lazy_segtree<S, op, e, F, mapping, composition, id> lsg1(n), lsg2(n);
    rep(i,n) {
        if( i%2 == 0 ) lsg1.set(i/2, S{s[i]-'0', 1});
        else lsg2.set(i/2, S{s[i]-'0', 1});
    }
    while( q-- ) {
        ll t, l, r; cin >> t >> l >> r;
        if( t == 1 ) {
            lsg1.apply(l/2, (r+1)/2, 1);
            lsg2.apply(((l+1)/2)-1, r/2, 1);
            // cerr << l/2 << ' ' << (r+1)/2 << ' ' << ((l+1)/2)-1 << ' ' << r/2 << endl;
        }
        else {
            ll l1 = lsg1.prod(l/2, (r+1)/2).value;
            ll l2 = lsg2.prod(((l+1)/2)-1, r/2).value;
            // cerr << l1 << ' ' << l2 << endl;
            bool flag = false;
            flag |= (l1 == 0 && l2 == r/2-(((l+1)/2)-1));
            flag |= (l1 == (r+1)/2-l/2 && l2 == 0);
            cout << (flag ? "Yes" : "No") << '\n' << flush;
        }
    }
    
    return 0;
}