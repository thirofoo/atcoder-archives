/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/34157890
 * Submitted at: 2022-08-20 16:42:28
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_l
 * Result: AC
 * Execution Time: 259 ms
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

struct S{
    ll value;
    ll zero;
    ll one;
};

//operator(作用素)
S op(S a,S b){
    S res{};
    //☆ここでの演算は二分木おける子から親へ伝搬してる計算のイメージ
    // => aとbは二つの子における演算ということ。(aが左,bが右の子)
    
    //value：転倒数 (aとbの転倒数に加えて、(aの0)*(bの1)だけ転倒数が増加)
    res.value=a.value+b.value+a.one*b.zero;
    //親のzeroとoneは子の和に等しい
    res.zero=a.zero+b.zero;
    res.one=a.one+b.one;
    return res;
}

// 写像 f(x) を返す (☆遅延されているデータを下層に反映)
S mapping(bool f,S x){
    //今回のmapping( f(x) )は0,1を反転する操作を意味する。
    if(f==0) return x;
    S res{};
    ll size=x.one+x.zero;
    //value；前半の項はP(1,0)orP(0,1)の選び方の総数、後半は転倒数
    // => valueは元の転倒してない数
    // => 01を反転した時の転倒数
    res.value= size*(size-1)/2-x.zero*(x.zero-1)/2-x.one*(x.one-1)/2 - x.value;
    //zero,one：01を反転
    res.zero=size-x.zero;
    res.one=size-x.one;
    return res;
}

// 合成写像 f o g を返す (非可換な場合に注。 g -> f の順番で処理。上層の遅延データを下層の遅延データに反映する際の処理。上書きの場合はfのみ処理。)
// 今回はfが反転する操作よりgをやった後にfをやるという合成写像は、g^fに一致。
bool composition(bool f,bool g){ return g^f; }

S e(){ return S{0,0,0}; } // 単位元 (op(e, a) = op(a, e) = a)
bool id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n,q; cin >> n >> q;
    vector<S> A;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        A.push_back(S{0, 1-a, a});
    }
    lazy_segtree<S, op, e, bool, mapping, composition, id> sg(A);
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1){
            //普通のセグ木と違って、区間を一斉更新している
            // => 普通だとO(WlogN) 遅延評価だとO(logN) ※Wは区間の広さ
            //applyで遅延されてる分を考慮。
            sg.apply(l, r, true);
        }
        else{
            //prod：今の状態におけるopの計算結果を得る
            cout << sg.prod(l, r).value << '\n';
        }
    }
 
    return 0;
}