/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34160427
 * Submitted at: 2022-08-20 18:54:35
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ac
 * Result: AC
 * Execution Time: 586 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

// S が data, F が lazy
using S = int;
using F = int;

//operator(作用素)
S op(S a,S b){
    //☆ここでの演算は二分木おける子から親へ伝搬して計算するイメージ
    return max(a,b);
}

// 写像 f(x) を返す (☆遅延されているデータを下層に反映)
S mapping(F f,S x){
    return max(f,x);
}

// 合成写像 f o g を返す (非可換な場合に注。 g -> f の順番で処理。上層の遅延データを下層の遅延データに反映する際の処理。上書きの場合はfのみ処理。)
F composition(F f,F g){
    return max(f,g);
}

S e(){ return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int w,n; cin >> w >> n;
    lazy_segtree<S,op,e,F,mapping,composition,id> sg(w+1);
    while(n--){
        int l,r,v; cin >> l >> r; l--;
        v = sg.prod(l,r)+1;
        sg.apply(l,r,v);
        cout << v << endl;
    }
    
    return 0;
}